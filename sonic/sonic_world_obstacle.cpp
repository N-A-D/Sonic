#include "sonic_world_obstacle.h"

sonic::world::obstacle::obstacle(double radius, math::vec2D pos)
	: sonic::util::instance_counter<sonic::world::obstacle>(), idx(instance_count()), r(radius), p(pos)
{
}

double sonic::world::obstacle::radius() const noexcept
{
	return r;
}

sonic::math::vec2D sonic::world::obstacle::pos() const noexcept
{
	return p;
}

std::size_t sonic::world::obstacle::id() const noexcept
{
	return idx;
}

bool sonic::world::operator<(const obstacle & a, const obstacle & b) noexcept
{
	return a.id() < b.id();
}

bool sonic::world::operator>(const obstacle & a, const obstacle & b) noexcept
{
	return b < a;
}

bool sonic::world::operator==(const obstacle & a, const obstacle & b) noexcept
{
	return !(a < b) && !(b < a);
}

bool sonic::world::operator!=(const obstacle & a, const obstacle & b) noexcept
{
	return !(a == b);
}