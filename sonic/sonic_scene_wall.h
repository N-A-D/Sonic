#include "sonic_math_vec2D.h"
#include "sonic_util_instance_counter.h"

namespace sonic {
	namespace scene {
		
		// The wall class
		// Defined by the two vectors start and end
		class wall : public sonic::util::instance_counter<wall> {
		public:
			wall(const math::vec2D& start, const math::vec2D& end);
			// Returns the start point of the wall
			math::vec2D start() const noexcept;
			// Returns the end point of the wall
			math::vec2D end() const noexcept;
			// Returns the center of the wall
			math::vec2D center() const noexcept;
			// Returns a vector perpendicular to end - start
			// The returned vector is a unit vector with direction left of end - start
			math::vec2D norm() const noexcept;
			// Returns the id of this wall
			std::size_t id() const noexcept;
		private:
			std::size_t idx;
			math::vec2D s, e;
		};

		bool operator<(const wall& a, const wall& b) noexcept;
		bool operator>(const wall& a, const wall& b) noexcept;
		bool operator==(const wall& a, const wall& b) noexcept;
		bool operator!=(const wall& a, const wall& b) noexcept;

	}
}