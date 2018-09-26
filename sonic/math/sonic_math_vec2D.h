#pragma once

#include <stdexcept>
#include "sonic_math_functions.h"
#include "sonic_math_matrix.h"
namespace sonic {
	namespace math {

		// 2D space vector
		template <class T>
		struct vec2 {

			// Constructors
			vec2() = default;
			vec2(T x, T y) : x(x), y(y) {}

			// Returns the length
			T length() const noexcept { return sqrt(pow(x, 2) + pow(y, 2)); }

			// Returns the length squared
			T length_sq() const noexcept { return pow(x, 2) + pow(y, 2); }

			// Returns the distance to other
			T dist_to(const vec2<T>& other) const noexcept { return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2)); }

			// Returns the distance to other squared
			T dist_to_sq(const vec2<T>& other) const noexcept { return pow(other.x - x, 2) + pow(other.y - y, 2); }

			// Returns the angle to another vector in degrees
			T angle_to(const vec2<T>& other) const {
				auto v = this->norm();
				auto w = other.norm();
				return sonic::math::degrees(acos(v.dot(w)));
			}

			// Returns the dot product between the caller and other
			T dot(const vec2<T>& other) const noexcept { return x * other.x + y * other.y; }

			// Returns a copy of the caller rotated by angle (degrees)
			vec2<T> rotate(T angle) const noexcept {
				auto rads = sonic::math::radians(angle);
				auto t_x = x * cos(rads) - y * sin(rads);
				auto t_y = x * sin(rads) + y * cos(rads);
				return vec2<T>(t_x, t_y);
			}

			// Returns a copy of the caller normalized
			vec2<T> norm() const {
				auto mag = this->length();
				if (mag == 0) throw std::runtime_error("Cannot normalize a vector of length zero!");
				return vec2<T>(x / mag, y / mag);
			}

			// Returns a copy of the the caller truncated to size
			vec2<T> trunc(T size) const {
				return this->norm() * size;
			}

			// Returns a vector that is perpendicular to the calling vector
			vec2<T> perp() const noexcept {
				return vec2<T>(-y, x);
			}

			// Turns the caller into the zero vector
			void zero() noexcept { x = 0; y = 0; }

			// Returns whether or not this vector is the zero vector
			bool is_zero() const noexcept { return this->length() == 0; }

			// Operators
			vec2<T>& operator+=(const vec2<T>& other) noexcept {
				x += other.x;
				y += other.y;
				return *this;
			}
			vec2<T>& operator-=(const vec2<T>& other) noexcept {
				x -= other.x;
				y -= other.y;
				return *this;
			}
			vec2<T>& operator*=(T scale) noexcept {
				x *= scale;
				y *= scale;
				return *this;
			}
			vec2<T>& operator/=(T scale) {
				if (scale == 0) throw std::runtime_error("Cannot divide a vector by zero!");
				x /= scale;
				y /= scale;
				return *this;
			}

			T x, y;

		};

		// Additional operators
		template <class T> vec2<T> operator+(const vec2<T>& lhs, const vec2<T>& rhs) noexcept { return vec2<T>(lhs) += rhs; }
		template <class T> vec2<T> operator-(const vec2<T>& lhs, const vec2<T>& rhs) noexcept { return vec2<T>(lhs) -= rhs; }
		template <class T> vec2<T> operator*(const vec2<T>& lhs, double scale) noexcept { return vec2<T>(lhs) *= scale; }
		template <class T> vec2<T> operator*(double scale, const vec2<T>& rhs) noexcept { return rhs * scale; }
		template <class T> vec2<T> operator/(const vec2<T>& lhs, double scale) { return vec2<T>(lhs) /= scale; }
		template <class T> bool operator==(const vec2<T>& lhs, const vec2<T>& rhs) noexcept { return sonic::math::approx_equal(lhs.x, rhs.x) && sonic::math::approx_equal(lhs.y, rhs.y); }
		template <class T> bool operator!=(const vec2<T>& lhs, const vec2<T>& rhs) noexcept { return !(lhs == rhs); }

		// Syntactic sugar
		using vec2D = vec2<double>;
		using vec2Df = vec2<float>;
	}
}
