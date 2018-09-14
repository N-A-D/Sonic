#pragma once

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

#include <assert.h>
#include <random>

namespace sonic {
	namespace math {

		// Returns true if two real numbers are approxmiately equal
		// That is, if the absolute difference between the two numbers a and b is less than EPSILON
		template <class T>
		typename std::enable_if<std::is_floating_point<T>::value, bool>::type 
			approx_equal(T a, T b) noexcept {
			return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
		}

		// Converts from degrees to radians
		template <class T>
		typename std::enable_if<std::is_floating_point<T>::value, T>::type
			deg_to_rad(T deg) noexcept {
			return static_cast<T>(M_PI) / static_cast<T>(180) * deg;
		}

		// Converts from radians to degrees
		template <class T>
		typename std::enable_if<std::is_floating_point<T>::value, T>::type
			rad_to_deg(T rad) noexcept {
			return rad * static_cast<T>(180) / static_cast<T>(M_PI);
		}

		// Returns a uniformly distributed interger in the 
		// range specified by x and y inclusive
		template <class T>
		typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type
			rand_int(T min, T max) noexcept {
			assert(min <= max);
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<T> dis(min, max);
			return dis(gen);
		}

		// Returns a uniformly distributed real value in 
		// the range specified by x and y inclusive
		template <class T>
		typename std::enable_if<std::is_floating_point<T>::value, T>::type
			rand_in_range(T min, T max) noexcept {
			assert(min <= max);
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<T> dis(min, max);
			return dis(gen);
		}

		// Returns a uniformly distributed real value 
		// between 0 and 1 inclusive
		template <class T>
		typename std::enable_if<std::is_floating_point<T>::value, T>::type
			random() noexcept {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<T> dis(static_cast<T>(0), static_cast<T>(1));
			return dis(gen);
		}

	}
}