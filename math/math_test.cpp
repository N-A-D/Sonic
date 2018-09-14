#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\sonic\sonic_math_vec2D.h"
#include "..\sonic\sonic_math_functions.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace math
{		
	TEST_CLASS(vec2D)
	{
	public:

		TEST_METHOD(length)
		{
			sonic::math::vec2D v(3, 4);
			Assert::IsTrue(v.length() == 5);
		}

		TEST_METHOD(length_sq) {
			sonic::math::vec2D v(3, 4);
			Assert::IsTrue(v.length_sq() == 25);
		}

		TEST_METHOD(dist_to) {
			sonic::math::vec2D a(3, 4);
			sonic::math::vec2D b(5, 6);
			Assert::IsTrue(a.dist_to(b) == sqrt(pow((5 - 3), 2) + pow(6 - 4, 2)));
		}

		TEST_METHOD(dist_to_sq) {
			sonic::math::vec2D a(3, 4);
			sonic::math::vec2D b(5, 6);
			Assert::IsTrue(a.dist_to_sq(b) == 8);
		}

		TEST_METHOD(angle_to) {
			sonic::math::vec2D v1(1, 0);
			sonic::math::vec2D v2(0, 1);
			Assert::IsTrue(sonic::math::approx_equal(v1.angle_to(v2), 90.0));
		}

		TEST_METHOD(rotate) {
			sonic::math::vec2D a(1, 0);
			a = a.rotate(90);
			Assert::IsTrue(sonic::math::approx_equal(a.x, 0.0) && sonic::math::approx_equal(a.y, 1.0));
			sonic::math::vec2D b(0, 1);
			b = b.rotate(-90);
			Assert::IsTrue(sonic::math::approx_equal(b.x, 1.0) && sonic::math::approx_equal(b.y, 0.0));
		}

		TEST_METHOD(norm) {
			sonic::math::vec2D v(3, 4);
			Assert::IsTrue(v.length() == 5);
			v = v.norm();
			Assert::IsTrue(v.length() == 1);
		}

		TEST_METHOD(scale) {
			sonic::math::vec2D v(3, 4);
			Assert::IsTrue(v.length() == 5);
			v = v.trunc(10);
			Assert::IsTrue(v.length() == 10);
		}

		TEST_METHOD(dot) {
			sonic::math::vec2D v(1, 0);
			Assert::IsTrue(v.dot(sonic::math::vec2D(0, 1)) == 0);
			v.x = -1, 0;
			Assert::IsTrue(v.dot(sonic::math::vec2D(1, 0)) == -1);
		}

		TEST_METHOD(perp) {
			sonic::math::vec2D v(3, 4);
			auto w = v.perp();
			Assert::IsTrue(w.dot(v) == 0);
		}

		TEST_METHOD(is_zero) {
			sonic::math::vec2D v(3, 4);
			Assert::IsFalse(v.is_zero());
			v.zero();
			Assert::IsTrue(v.is_zero());
		}

		TEST_METHOD(compound_addition) {
			sonic::math::vec2D v1(3, 4);
			sonic::math::vec2D v2(3, 4);
			v1 += v2;
			Assert::IsTrue(v1.x == 6 && v1.y == 8);
		}

		TEST_METHOD(compound_subtraction) {
			sonic::math::vec2D v1(3, 4);
			sonic::math::vec2D v2(3, 4);
			v1 -= v2;
			Assert::IsTrue(v1.x == 0 && v1.y == 0);
		}

		TEST_METHOD(compound_multiplication) {
			sonic::math::vec2D v1(3, 4);
			v1 *= 3;
			Assert::IsTrue(v1.x == 9 && v1.y == 12);
		}

		TEST_METHOD(compound_division) {
			sonic::math::vec2D v1(12, 16);
			v1 /= 4;
			Assert::IsTrue(v1.x == 3 && v1.y == 4);
		}

		TEST_METHOD(addition) {
			// Addition
			auto v2 = sonic::math::vec2D(3, 4) + sonic::math::vec2D(1, 1);
			Assert::IsTrue(v2.x == 4 && v2.y == 5);
		}

		TEST_METHOD(subtraction) {
			auto v = sonic::math::vec2D(3, 4) - sonic::math::vec2D(1, 1);
			Assert::IsTrue(v.x == 2 && v.y == 3);
		}

		TEST_METHOD(multiplcation) {
			auto v = sonic::math::vec2D(3, 4) * 3;
			Assert::IsTrue(v.x == 9 && v.y == 12);
			v = 3 * sonic::math::vec2D(3, 4);
			Assert::IsTrue(v.x == 9 && v.y == 12);
		}

		TEST_METHOD(division) {
			auto v = sonic::math::vec2D(9, 12) / 3;
			Assert::IsTrue(v.x == 3 && v.y == 4);
		}
	};

	TEST_CLASS(funtions) {
	public:

		TEST_METHOD(approx_equal) {
			Assert::IsTrue(sonic::math::approx_equal(1e-52, 1.5e-52));
			Assert::IsFalse(sonic::math::approx_equal(0.02, 0.017));
		}
		
		TEST_METHOD(deg_to_rad) {
			Assert::IsTrue(sonic::math::approx_equal(1.57079632679489661923, sonic::math::deg_to_rad(90.0)));
		}

		TEST_METHOD(rad_to_deg) {
			Assert::IsTrue(sonic::math::approx_equal(90.0, sonic::math::rad_to_deg(1.57079632679489661923)));
		}

		TEST_METHOD(rand_int) {
			int value = sonic::math::rand_int(11, 100);
			Assert::IsTrue(11 <= value && value <= 100);
		}

		TEST_METHOD(rand_in_range) {
			double value = sonic::math::rand_in_range(static_cast<double>(10), static_cast<double>(20));
			Assert::IsTrue(10 <= value && value <= 20);
		}

		TEST_METHOD(random) {
			double value = 0;
			value = sonic::math::random<double>();
			Assert::IsTrue(0 <= value && value <= 1);
		}

	};
}