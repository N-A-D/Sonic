#include "sonic_scene_wall.h"

sonic::scene::wall::wall(const math::vec2D & start, const math::vec2D & end)
	: sonic::util::instance_counter<sonic::scene::wall>(), idx(instance_count()), s(start), e(end)
{
}

sonic::math::vec2D sonic::scene::wall::start() const noexcept
{
	return s;
}

sonic::math::vec2D sonic::scene::wall::end() const noexcept
{
	return e;
}

sonic::math::vec2D sonic::scene::wall::center() const noexcept
{
	return (e - s) / 2.0;
}

sonic::math::vec2D sonic::scene::wall::norm() const noexcept
{
	return (e - s).norm().perp();
}

std::size_t sonic::scene::wall::id() const noexcept
{
	return idx;
}

bool sonic::scene::operator<(const wall & a, const wall & b) noexcept
{
	return a.id() < b.id();
}

bool sonic::scene::operator>(const wall & a, const wall & b) noexcept
{
	return b < a;
}

bool sonic::scene::operator==(const wall & a, const wall & b) noexcept
{
	return !(a < b) && !(b < a);
}

bool sonic::scene::operator!=(const wall & a, const wall & b) noexcept
{
	return !(a == b);
}
