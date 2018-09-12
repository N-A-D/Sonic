#include "sonic_math_functions.h"
#include "sonic_math_constants.h"
#include <random>

bool sonic::math::approx_equal(double a, double b) noexcept
{
	return fabs(a - b) <= EPSILON;
}

double sonic::math::deg_to_rad(double deg) noexcept
{
	return M_PI / 180.0 * deg;
}

double sonic::math::rad_to_deg(double rad) noexcept
{
	return rad * 180 / M_PI;
}

int sonic::math::rand_int(int x, int y) noexcept
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(x, y);
	return dis(gen);
}

double sonic::math::rand_in_range(double x, double y) noexcept
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(x, y);
	return dis(gen);
}

double sonic::math::random() noexcept
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}

bool sonic::math::is_zero(double value) noexcept
{
	return value > -MINDOUBLE && value < MINDOUBLE;
}
