#pragma once

#include "sonic_math_vec2D.h"
#include "sonic_util_instance_counter.h"

namespace sonic {
	namespace world {
		
		// The obstacle class
		// Defined as a position and a radius
		class obstacle : public sonic::util::instance_counter<obstacle> {
		public:
			obstacle(double radius, math::vec2D pos);
			// Returns the radius of this obstacle
			double radius() const noexcept;
			// Returns the position of this obstacle
			math::vec2D pos() const noexcept;
			// Returns the obstacle id
			std::size_t id() const noexcept;
		private:
			std::size_t idx;
			double r;
			math::vec2D p;
		};

		bool operator<(const obstacle& a, const obstacle& b) noexcept;
		bool operator>(const obstacle& a, const obstacle& b) noexcept;
		bool operator==(const obstacle& a, const obstacle& b) noexcept;
		bool operator!=(const obstacle& a, const obstacle& b) noexcept;

	}
}