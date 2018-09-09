#pragma once

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // !_USE_MATH_DEFINES

#include <cmath>

namespace sonic {
	namespace math {

		// Returns true if two real numbers are approxmiately equal
		// That is, if the absolute difference between the two numbers is less than EPSILON
		bool is_equal(double a, double b);

		// Converts from degrees to radians
		double deg_to_rad(double deg);

		// Converts from radians to degrees
		double rad_to_deg(double rad);

		// Returns a uniformly distributed interger in the 
		// range specified by x and y inclusive
		int rand_int(int x, int y);

		// Returns a uniformly distributed real value in 
		// the range specified by x and y inclusive
		double rand_in_range(double x, double y);

		// Returns a uniformly distributed real value 
		// between 0 and 1 inclusive
		double random();

		// Checks if a numeric value is zero
		bool is_zero(double value);

		template <class T>
		int sign(T val) {
			return (T(0) < val) - (val < T(0));
		}

	}
}