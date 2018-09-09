#include <assert.h>
#include "sonic_math_vec2D.h"
#include "sonic_math_functions.h"
#include "sonic_math_constants.h"

using sonic::math::vec2D;

sonic::math::vec2D::vec2D() : x(0), y(0)
{
}

sonic::math::vec2D::vec2D(double x, double y) : x(x), y(y)
{
}

double sonic::math::vec2D::length() const
{
	return sqrt(x * x + y * y);
}

double sonic::math::vec2D::length_sq() const
{
	return pow(x, 2) + pow(y, 2);
}

double sonic::math::vec2D::dist_to(const vec2D & other) const
{
	return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

double sonic::math::vec2D::dist_to_sq(const vec2D & other) const
{
	return pow(other.x - x, 2) + pow(other.y - y, 2);
}

double sonic::math::vec2D::angle_to(const vec2D & other) const
{
	auto v = this->norm();
	auto w = other.norm();
	return rad_to_deg(acos(v.dot(w)));
}

vec2D sonic::math::vec2D::rotate(double angle) const
{
	double rads = deg_to_rad(angle);
	double t_x = x * cos(rads) - y * sin(rads);
	double t_y = x * sin(rads) + y * cos(rads);
	return vec2D(t_x, t_y);
}

vec2D sonic::math::vec2D::norm() const
{
	double magnitude = this->length();
	assert(magnitude == 0 && "Cannot normalize a vector of length zero!");
	return vec2D(x / magnitude, y / magnitude);
}


void sonic::math::vec2D::scale(double size)
{
	vec2D temp = this->norm();
	temp.x *= size;
	temp.y *= size;
	*this = temp;
}

double sonic::math::vec2D::dot(const vec2D & other) const
{
	return x * other.x + y * other.y;
}

vec2D sonic::math::vec2D::perp() const
{
	return vec2D(-y, x);
}

void sonic::math::vec2D::zero()
{
	this->x = 0;
	this->y = 0;
}

bool sonic::math::vec2D::is_zero() const
{
	return (x * x + y * y) < MINDOUBLE;
}

vec2D & sonic::math::vec2D::operator+=(const vec2D & other)
{
	x += other.x;
	y += other.y;
	return *this;
}

vec2D & sonic::math::vec2D::operator-=(const vec2D & other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

vec2D & sonic::math::vec2D::operator*=(double scale)
{
	x *= scale;
	y *= scale;
	return *this;
}

vec2D & sonic::math::vec2D::operator/=(double scale)
{
	assert(scale == 0 && "Cannot divide a vector by zero!");
	x /= scale;
	y /= scale;
	return *this;
}

vec2D sonic::math::operator+(const vec2D & lhs, const vec2D & rhs)
{
	vec2D r = lhs;
	r += rhs;
	return r;
}

vec2D sonic::math::operator-(const vec2D & lhs, const vec2D & rhs)
{
	vec2D r = lhs;
	r -= rhs;
	return r;
}

vec2D sonic::math::operator*(const vec2D & lhs, double scale)
{
	vec2D r = lhs;
	r *= scale;
	return r;
}

vec2D sonic::math::operator*(double scale, const vec2D & rhs)
{
	return rhs * scale;
}

vec2D sonic::math::operator/(const vec2D & lhs, double scale)
{
	vec2D r = lhs;
	r /= scale;
	return r;
}

vec2D sonic::math::operator/(double scale, const vec2D & rhs)
{
	return rhs * scale;
}

bool sonic::math::operator<(const vec2D & lhs, const vec2D & rhs)
{
	return lhs.length_sq() < rhs.length_sq();
}

bool sonic::math::operator>(const vec2D & lhs, const vec2D & rhs)
{
	return rhs < lhs;
}

bool sonic::math::operator==(const vec2D & lhs, const vec2D & rhs)
{
	return approx_equal(lhs.x, rhs.x) && approx_equal(lhs.y, rhs.y);
}

bool sonic::math::operator!=(const vec2D & lhs, const vec2D & rhs)
{
	return !(lhs == rhs);
}
