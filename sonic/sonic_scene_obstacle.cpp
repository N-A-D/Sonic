#include "sonic_scene_obstacle.h"

sonic::scene::obstacle::obstacle(double radius, math::vec2D pos)
	: sonic::util::instance_counter<sonic::scene::obstacle>(), idx(instance_count()), r(radius), p(pos)
{
}

double sonic::scene::obstacle::radius() const noexcept
{
	return r;
}

sonic::math::vec2D sonic::scene::obstacle::pos() const noexcept
{
	return p;
}

std::size_t sonic::scene::obstacle::id() const noexcept
{
	return idx;
}

bool sonic::scene::operator<(const obstacle & a, const obstacle & b) noexcept
{
	return a.id() < b.id();
}

bool sonic::scene::operator>(const obstacle & a, const obstacle & b) noexcept
{
	return b < a;
}

bool sonic::scene::operator==(const obstacle & a, const obstacle & b) noexcept
{
	return !(a < b) && !(b < a);
}

bool sonic::scene::operator!=(const obstacle & a, const obstacle & b) noexcept
{
	return !(a == b);
}