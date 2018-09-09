#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\sonic\sonic_util_rectangle.h"
#include <SDL.h>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangle
{		
	TEST_CLASS(rectangle)
	{
	public:
		
		TEST_METHOD(area)
		{
			sonic::util::rectangle rect(100, 100, 10, 10);
			Assert::IsTrue(rect.area() == 100);
		}

		TEST_METHOD(move) {
			sonic::util::rectangle rect(10, 10, 10, 10);
			rect = rect.move(90, 90);
			Assert::IsTrue(rect.x == 100 && rect.y == 100);
		}

		TEST_METHOD(copy) {
			sonic::util::rectangle a(100, 100, 10, 10);
			sonic::util::rectangle b(a);
			Assert::IsTrue(a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h);
			a = a.move(10, 10);
			Assert::IsTrue(a.x != b.x && a.y != b.y && a.w == b.w && a.h == b.h);
		}

		TEST_METHOD(inflate) {
			sonic::util::rectangle a(100, 100, 10, 10);
			a.inflate_ip(10, 10);
			Assert::IsTrue(a.w == 20 && a.h == 20);
			a = a.inflate(10, 10);
			Assert::IsTrue(a.w == 30 && a.h == 30);
		}

		TEST_METHOD(clip) {
			sonic::util::rectangle a(100, 100, 10, 10);
			auto b = a.clip(5, 5);
			Assert::IsTrue(b.w == 5 && b.h == 5);
		}

		TEST_METHOD(union_rect) {
			sonic::util::rectangle a(0, 0, 10, 10);
			std::vector<sonic::util::rectangle> rects;
			rects.push_back(sonic::util::rectangle(30, 120, 15, 15));
			rects.push_back(sonic::util::rectangle(120, 30, 200, 10));
			a = a.union_rect_all(rects.begin(), rects.end());
			Assert::IsTrue(a.x == 0 && a.y == 0 && a.w == 320 && a.h == 135);
		}

		TEST_METHOD(contains_rect) {
			sonic::util::rectangle a(0, 0, 10, 10);
			Assert::IsTrue(a.contains_rect(sonic::util::rectangle(2, 2, 2, 2)));
			Assert::IsFalse(a.contains_rect(sonic::util::rectangle(9, 9, 2, 2)));
			Assert::IsFalse(a.contains_rect(sonic::util::rectangle(19, 19, 12, 12)));
		}

		TEST_METHOD(contains_point) {
			sonic::util::rectangle a(0, 0, 10, 10);
			Assert::IsTrue(a.contains_point({4, 5}));
			Assert::IsTrue(a.contains_point({2, 9}));
			Assert::IsFalse(a.contains_point({ 11, 11 }));
			Assert::IsFalse(a.contains_point({ 8, 11 }));
		}

		TEST_METHOD(intersects_with) {
			sonic::util::rectangle a(0, 0, 10, 10);
			Assert::IsTrue(a.intersects_with(sonic::util::rectangle(4, 6, 11, 11)));
			Assert::IsFalse(a.intersects_with(sonic::util::rectangle(14, 6, 11, 11)));
		}

		TEST_METHOD(intersects_all) {
			sonic::util::rectangle a(0, 0, 10, 10);
			std::vector<sonic::util::rectangle> rects;
			rects.push_back(sonic::util::rectangle(3, 7, 111, 23));
			rects.push_back(sonic::util::rectangle(-100, 3, 111, 50));
			rects.push_back(sonic::util::rectangle(11, 8, 11, 74));
			rects.push_back(sonic::util::rectangle(10, 6, 67, 66));
			std::vector<sonic::util::rectangle> output;
			Assert::IsFalse(a.intersects_all(rects.begin(), rects.end(), std::back_inserter(output)));
			Assert::IsTrue(output.size() == 2);
		}
	};
}