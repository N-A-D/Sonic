#pragma once

#include <map>
#include <list>
#include <vector>
#include <numeric>
#include <functional>
#include "sonic_math_vec2D.h"
#include "sonic_util_rectangle.h"

namespace sonic {
	namespace scene {

		// Divides space into cells
		template <class Entity>
		class cell_space_partition {
		public:

			// The internal cell type
			struct cell_t {
				cell_t(int x, int y, int w, int h) : boundary(x, y, w, h) {}
				sonic::util::rectangle boundary;
				std::list<Entity> members;
			};
			
			cell_space_partition(int world_width, int world_height, int num_cells_x, int num_cells_y)
				: world_width(world_width)
				, world_height(world_height)
				, num_cells_x(num_cells_x == 0 ? 1 : std::abs(num_cells_x))
				, num_cells_y(num_cells_y == 0 ? 1 : std::abs(num_cells_y))
			{
				int cell_width = world_width / num_cells_x;
				int cell_height = world_height / num_cells_y;
				// Cells are stored in column major form
				for (int x = 0; x < num_cells_x; x++) {
					for (int y = 0; y < num_cells_y; y++) {
						grid.push_back(cell_t(x* cell_width, y * cell_height, cell_width, cell_height));
					}
				}

			}

			// Returns the number of entities contained by this cell space grid
			std::size_t entities() const noexcept {
				return std::accumulate(grid.begin(), grid.end(), std::size_t(0), [](std::size_t n, cell_t cell) { return n + cell.members.size(); });
			}
			
			// Returns the appropriate cell space for the given position
			std::size_t cell_for(const math::vec2D& pos) const noexcept {
				// formula -> column_length * column + row
				std::size_t idx = num_cells_y * 
					              static_cast<std::size_t>(num_cells_x * pos.x / world_width) + 
					              static_cast<std::size_t>(num_cells_y * pos.y / world_height);
				return (idx < grid.size()) ? idx : grid.size() - 1;
			}

			// Adds a new entity into the appropriate cell space
			void add_entity(const Entity& entity, const math::vec2D& pos) noexcept {
				auto idx = cell_for(pos);
				grid.at(idx).members.push_back(entity);
			}

			// Removes an entity from the appropriate cell space
			void remove_entity(const Entity& entity, const math::vec2D& pos) noexcept {
				auto idx = cell_for(pos);
				grid.at(idx).members.remove(entity);
			}

			// Moves an entity from one cell space to another
			void update_entity(const Entity& entity, math::vec2D old_pos, math::vec2D new_pos) noexcept {
				auto old_idx = cell_for(old_pos);
				auto new_idx = cell_for(new_pos);
				if (old_idx != new_idx) {
					grid.at(old_idx).members.remove(entity);
					grid.at(new_idx).members.push_back(entity);
				}
			}

			// Applies a function f onto any entity within a proximity circle
			void each_neighbor(const math::vec2D& position, double proximity_radius, std::function<void(Entity e)>&& function) noexcept {
				each_neighbor_if(position, proximity_radius, function, [](Entity e) { return true; });
			}

			// Applies a function f onto entities within the proximity circle and satisfy the filter functor
			void each_neighbor_if(const math::vec2D& position, double proximity_radius, std::function<void(Entity e)>&& function, std::function<void(Entity e)>&& filter) noexcept {
				util::rectangle prox_box(static_cast<int>(pos.x - proximity_radius / 2.0), 
					                     static_cast<int>(pos.y - proximity_radius / 2.0),
					                     proximity_radius, proximity_radius);
				for (auto cell : grid) {
					if (prox_box.intersects_with(cell.boundary)) {
						for (auto member : cell.members) {
							if (filter(member)) {
								function(member);
							}
						}
					}
				}
			}

		private:

			// The cell space grid
			std::vector<cell_t> grid;

			// The dimensions of the world in 2D
			int world_width, world_height;

			// The number of cells vertically and horizontally
			int num_cells_x, num_cells_y;
		};

	}
}