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
			v.scale(10);
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
		}
	};

	TEST_CLASS(funtions) {
	public:

		TEST_METHOD(approx_equal) {
			Assert::IsTrue(sonic::math::approx_equal(0.0000000000000000000000555, 0.00000000000000000000000000021));
			Assert::IsFalse(sonic::math::approx_equal(0.0123, 0.124));
		}
		TEST_METHOD(DegToRad) {
			// Why you no work M_PI_2?
			Assert::IsTrue(sonic::math::approx_equal(1.57079632679489661923, sonic::math::deg_to_rad(90.0)));
		}

		TEST_METHOD(RadToDeg) {
			// M_PI_2!!!!!!!
			Assert::IsTrue(sonic::math::approx_equal(90.0, sonic::math::rad_to_deg(1.57079632679489661923)));
		}

		TEST_METHOD(RandINT) {
			int x = sonic::math::rand_int(1, 10);
			Assert::IsTrue(x >= 1 && x <= 10);
		}

		TEST_METHOD(RandInRange) {
			double x = sonic::math::rand_in_range(75, 75.5);
			Assert::IsTrue(x >= 75.0 && x <= 75.5);
		}

		TEST_METHOD(RandomZeroOne) {
			double x = sonic::math::random();
			Assert::IsTrue(x >= 0 && x <= 1);
		}

		TEST_METHOD(Zero) {
			double x = 5.2e-400; // hella small
			Assert::IsTrue(sonic::math::is_zero(x));
		}
	};
}