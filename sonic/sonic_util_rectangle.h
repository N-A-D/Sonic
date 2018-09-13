#pragma once

#include <SDL.h>

namespace sonic {
	namespace util {

		// rectangle class
		struct rectangle {

			rectangle(int x = 0, int y = 0, int w = 0, int h = 0);

			// Conversion operator to SDL_Rect for functions
			// taking SDL_Rects
			operator SDL_Rect() const noexcept;

			// Returns whether or not this rectangle has zero size
			operator bool() const noexcept;

			// Returns the area of the rectangle
			int area() const noexcept;

			// Returns a new rectangle moved by the given offset
			rectangle move(int offset_x, int offset_y) const noexcept;

			// Returns a copy of the calling rectangle
			rectangle copy() const noexcept;

			// inflates the dimensions of the rectangle in place
			void inflate_ip(int width, int height) noexcept;

			// inflates the dimensions of the rectangle
			rectangle inflate(int width, int height) const noexcept;

			// Returns a clip of the calling rectangle
			rectangle clip(int width, int height) const noexcept;

			// Combines two rectangles into one in place
			void union_rect_ip(const rectangle& rect) noexcept;

			// Combines two rectangles into one
			rectangle union_rect(const rectangle& rect) const noexcept;

			// Combines many rectangles into one in place
			template <class T>
			void union_rect_all_ip(T begin, T end) noexcept;

			// Combines many rectangles into one
			template <class T>
			rectangle union_rect_all(T begin, T end) const noexcept;

			// Checks if a rectangle is inside a rectangle
			bool contains_rect(const rectangle& rect) const noexcept;

			// Checks if a point is inside a rectangle
			bool contains_point(const SDL_Point& point) const noexcept;

			// Checks if two rectangles intersect
			bool intersects_with(const rectangle& other) const noexcept;

			// Checks if multiple rectangles intersect with the caller
			// The intersecting rectangles are placed inside of result
			template <class In, class Out>
			bool intersects_all(In begin, In end, Out intersect_rects) const noexcept;


			//------------------------- Getters and Setters --------------------------//

			// Returns the rectangle's width component
			int width() const noexcept;

			// Returns the rectangle's height component
			int height() const noexcept;

			// Sets this rectangle's width component
			void set_width(int val) noexcept;

			// Sets this rectangle's height component
			void set_height(int val) noexcept;

			// Returns the center of the rectangle
			SDL_Point center() const noexcept;

			// Returns the top left corner of the rectangle
			SDL_Point top_left() const noexcept;

			// Returns the top mid of the rectangle
			SDL_Point top_mid() const noexcept;

			// Returns the top right of the rectangle
			SDL_Point top_right() const noexcept;

			// Returns the mid right of the rectangle
			SDL_Point mid_right() const noexcept;

			// Returns the btm right of the rectangle
			SDL_Point btm_right() const noexcept;

			// Returns the btm mid of the rectangle
			SDL_Point btm_mid() const noexcept;

			// Returns the btm left of the rectangle
			SDL_Point btm_left() const noexcept;

			// Returns the mid left of the rectangle
			SDL_Point mid_left() const noexcept;

			// Sets the center of the rectangle
			void set_center(int x, int y) noexcept;

			// Sets the top left of the rectangle
			void set_top_left(int x, int y) noexcept;

			// Sets the top mid of the rectangle
			void set_top_mid(int x, int y) noexcept;

			// /Sets the top right of the rectangle
			void set_top_right(int x, int y) noexcept;

			// Sets the mid right of the rectangle
			void set_mid_right(int x, int y) noexcept;

			// Sets the btm right of the rectangle
			void set_btm_right(int x, int y) noexcept;

			// Sets the mid btm of the rectangle
			void set_btm_mid(int x, int y) noexcept;

			// Sets the btm left of the rectangle
			void set_btm_left(int x, int y) noexcept;

			// Sets the mid of the rectangle
			void set_mid_left(int x, int y) noexcept;

			// Operators
			friend bool operator==(const rectangle& lhs, const rectangle& rhs) noexcept;
			friend bool operator!=(const rectangle& lhs, const rectangle& rhs) noexcept;

			// rectangle vars
			int x, y, w, h;
		};

		template<class T>
		inline void rectangle::union_rect_all_ip(T begin, T end) noexcept
		{
			for (T i = begin; i != end; ++i)
				union_rect_ip(*i);
		}

		template<class T>
		inline rectangle rectangle::union_rect_all(T begin, T end) const noexcept
		{
			rectangle r(x, y, w, h);
			r.union_rect_all_ip(begin, end);
			return r;
		}

		template<class In, class Out>
		inline bool rectangle::intersects_all(In begin, In end, Out intersect_rects) const noexcept
		{
			bool result = true;

			for (In i = begin; i != end; ++i) {
				if (!intersects_with(*i)) {
					result = false;
				}
				else {
					*intersect_rects++ = *i;
				}
			}

			return result;
		}

	}
}