#pragma once

#include <cctype>
#include <string>
#include <cstddef>
#include <assert.h>
#include <algorithm>
#include <unordered_map>
#include "sonic_resource.h"

namespace sonic {
	namespace resource {

		// Base resource class from which all resources derive
		class basic_resource_type {
		protected:
			static std::size_t resource_type_id;
		};

		// Any type that is a resource should subclass this class
		template <class Derived>
		class resource_type : public basic_resource_type {
		public:
			static std::size_t resource_id() noexcept {
				static std::size_t id = resource_type_id++;
				return id;
			}
		};

		// Responsible for the management of a variety of resource types
		class resouce_manager {
			using resource_table = std::unordered_map<std::string, std::shared_ptr<basic_resource_type>>;
			using resource_database = std::unordered_map<std::size_t, resource_table>;

			resouce_manager() {}

			// Manages a new type of resource
			template <class Resource>
			void manage() noexcept {
				if (!manages<Resource>()) {
					database.insert(std::make_pair(Resource::resource_id(), resource_table()));
				}
			}

			// Checks if this manager manges the given type of resource
			template <class Resource>
			bool manages() const noexcept {
				return database.find(Resource::resource_id()) != database.end();
			}

			// Removes all managed Resource objects
			template <class Resource>
			void clear() noexcept {
				assert(manages<Resource>());
				database.at(Resource::resource_id()).clear();
			}

			// Adds a new Resource object to this manager
			// Returns true if the addition took place; false otherwise
			template <class Resource, class... Args>
			bool add(std::string resource_name, Args&& ...args) noexcept {
				if (!manages<Resource>())
					manage<Resource>();

				resource_name = normalize_resource_name(resource_name);

				bool success = false;
				if (!has_aux<Resource>(resource_name)) {

					database.at(Resource::resource_id()).insert(
						std::make_pair(resource_name, std::make_shared<Resource>(std::forward<Args>(args)...)));
					success = true;
				}
				return success;
			}

			// Returns the Resource object reference
			template <class Resource>
			Resource& get(std::string resource_name) noexcept {
				resource_name = normalize_resource_name(resource_name);
				assert(has_aux<Resource>(resource_name));
				return *(std::static_pointer_cast<Resource>(database.at(Resource::resource_id()).at(resource_name)));
			}

			// Removes the Resource object associated with resource_name
			template <class Resource>
			void remove(std::string resource_name) noexcept {
				resource_name = normalize_resource_name(resource_name);
				assert(has_aux<Resource>(resource_name));
				database.at(Resource::resource_id()).erase(resource_name);
			}

			// Checks if this manager manages a Resource object named resource_name
			template <class Resource>
			bool has(std::string resource_name) const noexcept {
				return has_aux<Resource>(normalize_resource_name(resource_name));
			}

		private:

			// Checks if this manager manages a Resource object named resource_name without normalization
			template <class Resource>
			bool has_aux(std::string resource_name) const noexcept {
				assert(manages<Resource>());
				auto table = database.at(Resource::resource_id());
				return table.find(resource_name) != table.end();
			}

			// Returns a lowercase version of resource_name without any spaces or non alphanumeric characters
			std::string normalize_resource_name(std::string resource_name) const noexcept {
				resource_name.erase(std::remove_if(resource_name.begin(), resource_name.end(), [](unsigned char c) { return std::isspace(c) || !std::isalnum(c); }), resource_name.end());
				std::transform(resource_name.begin(), resource_name.end(), resource_name.begin(), [](unsigned char c) { return std::tolower(c); });
				return resource_name;
			}

			resource_database database;
		};

	}
}