#include "sonic_world_wall.h"

sonic::world::wall::wall(const math::vec2D & start, const math::vec2D & end)
	: sonic::util::instance_counter<sonic::world::wall>(), idx(instance_count()), s(start), e(end)
{
}

sonic::math::vec2D sonic::world::wall::start() const noexcept
{
	return s;
}

sonic::math::vec2D sonic::world::wall::end() const noexcept
{
	return e;
}

sonic::math::vec2D sonic::world::wall::center() const noexcept
{
	return (e - s) / 2.0;
}

sonic::math::vec2D sonic::world::wall::norm() const noexcept
{
	return (e - s).norm().perp();
}

std::size_t sonic::world::wall::id() const noexcept
{
	return idx;
}

bool sonic::world::operator<(const wall & a, const wall & b) noexcept
{
	return a.id() < b.id();
}

bool sonic::world::operator>(const wall & a, const wall & b) noexcept
{
	return b < a;
}

bool sonic::world::operator==(const wall & a, const wall & b) noexcept
{
	return !(a < b) && !(b < a);
}

bool sonic::world::operator!=(const wall & a, const wall & b) noexcept
{
	return !(a == b);
}
