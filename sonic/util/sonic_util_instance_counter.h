#pragma once

#include <cstddef>

namespace sonic {
	namespace util {

		// Enables instance counting
		template <class T>
		class instance_counter {
		public:
			instance_counter() { ++inst_count; }
			instance_counter(const instance_counter&) { ++inst_count; }
			virtual ~instance_counter() { --inst_count; }
			// 
			static std::size_t instance_count() noexcept { return inst_count; }
		private:
			static std::size_t inst_count;
		};

		template <class T>
		std::size_t instance_counter<T>::inst_count = 0;

	}
}