#include "sonic_util_rectangle.h"

using sonic::util::rectangle;

sonic::util::rectangle::rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
{
}

sonic::util::rectangle::operator SDL_Rect()
{
	return { x, y, w, h };
}

sonic::util::rectangle::operator bool()
{
	return w != 0 && h != 0;
}

int sonic::util::rectangle::area() const noexcept
{
	return w * h;
}

rectangle sonic::util::rectangle::move(int offset_x, int offset_y) const noexcept
{
	return rectangle(x + offset_x, y + offset_y, w, h);
}

rectangle sonic::util::rectangle::copy()
{
	return rectangle(x, y, w, h);
}

void sonic::util::rectangle::inflate_ip(int width, int height)
{
	w += width;
	h += height;
}

rectangle sonic::util::rectangle::inflate(int width, int height) const noexcept
{
	return rectangle(x, y, w + width, h + height);
}

rectangle sonic::util::rectangle::clip(int width, int height) const noexcept
{
	return rectangle(x, y, width, height);
}

void sonic::util::rectangle::union_rect_ip(const rectangle & rect)
{
	// Find the top left corner
	int x_min = x < rect.x ? x : rect.x;
	int y_min = y < rect.y ? y : rect.y;

	// Find the greatest width
	int x_max = x + w > rect.x + rect.w ? x + w : rect.x + rect.w;

	// Find the greatest height
	int y_max = y + h > rect.y + rect.h ? y + h : rect.y + rect.h;

	this->x = x_min;
	this->y = y_min;
	this->w = x_max - x_min;
	this->h = y_max - y_min;
}

rectangle sonic::util::rectangle::union_rect(const rectangle & rect) const noexcept
{
	rectangle r(x, y, w, h);
	r.union_rect_ip(rect);
	return r;
}

bool sonic::util::rectangle::contains_rect(const rectangle & rect) const noexcept
{
	return rect.x >= x
		&&
		rect.x + rect.w <= x + w
		&&
		rect.y >= y
		&&
		rect.y + rect.h <= y + h;
}

bool sonic::util::rectangle::contains_point(const SDL_Point & point) const noexcept
{
	return point.x >= x
		&&
		point.x <= x + w
		&&
		point.y >= y
		&&
		point.y <= y + h;
}

bool sonic::util::rectangle::intersects_with(const rectangle & other) const noexcept
{
	return other.x < x + w && other.x + other.w > x && other.y < y + h && other.y + other.h > y ? true : false;
}

SDL_Point sonic::util::rectangle::center() const noexcept
{
	return { x + w / 2, y + h / 2 };
}

SDL_Point sonic::util::rectangle::top_left() const noexcept
{
	return { x, y };
}

SDL_Point sonic::util::rectangle::top_mid() const noexcept
{
	return { x + w / 2, y };
}

SDL_Point sonic::util::rectangle::top_right() const noexcept
{
	return { x + w, y };
}

SDL_Point sonic::util::rectangle::mid_right() const noexcept
{
	return { x + w, y + h / 2 };
}

SDL_Point sonic::util::rectangle::btm_right() const noexcept
{
	return { x + w, y + h };
}

SDL_Point sonic::util::rectangle::btm_mid() const noexcept
{
	return { x + w / 2, y + h };
}

SDL_Point sonic::util::rectangle::btm_left() const noexcept
{
	return { x, y + h };
}

SDL_Point sonic::util::rectangle::mid_left() const noexcept
{
	return { x, y + h / 2 };
}

int sonic::util::rectangle::width() const noexcept
{
	return w;
}

int sonic::util::rectangle::height() const noexcept
{
	return h;
}

void sonic::util::rectangle::width(int val) noexcept
{
	w = val;
}

void sonic::util::rectangle::height(int val) noexcept
{
	h = val;
}

void sonic::util::rectangle::center(int x, int y) noexcept
{
	this->x = x - w / 2;
	this->y = y - h / 2;
}

void sonic::util::rectangle::top_left(int x, int y) noexcept
{
	this->x = x;
	this->y = y;
}

void sonic::util::rectangle::top_mid(int x, int y) noexcept
{
	this->x = x - w / 2;
	this->y = y;
}

void sonic::util::rectangle::top_right(int x, int y) noexcept
{
	this->x = x - w;
	this->y = y;
}

void sonic::util::rectangle::mid_right(int x, int y) noexcept
{
	this->x = x - w;
	this->y = y - h / 2;
}

void sonic::util::rectangle::btm_right(int x, int y) noexcept
{
	this->x = x - w;
	this->y = y - h;
}

void sonic::util::rectangle::btm_mid(int x, int y) noexcept
{
	this->x = x - w / 2;
	this->y = y - h;
}

void sonic::util::rectangle::btm_left(int x, int y) noexcept
{
	this->x = x;
	this->y = y - h;
}

void sonic::util::rectangle::mid_left(int x, int y) noexcept
{
	this->x = x;
	this->y = y - h / 2;
}

bool sonic::util::operator==(const rectangle & lhs, const rectangle & rhs) noexcept
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.w == rhs.w && lhs.h == rhs.h;
}

bool sonic::util::operator!=(const rectangle & lhs, const rectangle & rhs) noexcept
{
	return !(lhs == rhs);
}
