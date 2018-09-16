#include <assert.h>
#include <stdexcept>
#include "sonic_resource_texture.h"
#include "sonic_display_renderer.h"

sonic::display::renderer::renderer() : m_renderer(nullptr), w_id(0)
{
}

sonic::display::renderer::renderer(SDL_Renderer * r, std::uint32_t window_id) : w_id(window_id), m_renderer(std::shared_ptr<SDL_Renderer>(r, [](SDL_Renderer* r) { SDL_DestroyRenderer(r); }))
{
}


sonic::display::renderer::operator SDL_Renderer*() const noexcept
{
	assert(m_renderer && "Cannot convert an invalid renderer to SDL_renderer.");
	return m_renderer.get();
}

sonic::display::renderer::operator bool() const noexcept
{
	return m_renderer.get() != nullptr;
}

std::uint32_t sonic::display::renderer::window_id() const noexcept
{
	assert(m_renderer && "Cannot get the window id of an invalid m_renderer.");
	return w_id;
}

void sonic::display::renderer::set_viewport(const SDL_Rect & rect) noexcept
{
	assert(m_renderer && "Cannot set the viewport of an invalid m_renderer.");
	SDL_RenderSetViewport(m_renderer.get(), &rect);
}

void sonic::display::renderer::set_draw_color(const SDL_Color& color) noexcept
{
	assert(m_renderer && "Cannot set the draw color of an invalid m_renderer.");
	SDL_SetRenderDrawColor(this->m_renderer.get(), color.r, color.g, color.b, color.a);
}

SDL_Color sonic::display::renderer::draw_color() const noexcept
{
	assert(m_renderer && "Cannot get the draw color of an invalid m_renderer.");
	std::uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(m_renderer.get(), &r, &g, &b, &a);
	return { r, g, b, a };
}

void sonic::display::renderer::draw_line(const std::array<int, 4>& points) noexcept
{
	assert(m_renderer && "Cannot draw a line with an invalid m_renderer.");
	SDL_RenderDrawLine(m_renderer.get(), points[0], points[1], points[2], points[3]);
}

void sonic::display::renderer::draw_point(const SDL_Point & point) noexcept
{
	assert(m_renderer && "Cannot draw a point with an invalid m_renderer.");
	SDL_RenderDrawPoint(m_renderer.get(), point.x, point.y);
}

void sonic::display::renderer::draw_rectangle(const SDL_Rect & rect) noexcept
{
	assert(m_renderer && "Cannot draw a rectangle with an invalid m_renderer.");
	SDL_RenderDrawRect(m_renderer.get(), &rect);
}

void sonic::display::renderer::draw_filled_rectangle(const SDL_Rect & rect) noexcept
{
	assert(m_renderer && "Cannot draw a filled rectangle with an invalid m_renderer");
	SDL_RenderFillRect(m_renderer.get(), &rect);
}

void sonic::display::renderer::clear(const SDL_Color & color) noexcept
{
	assert(m_renderer && "Cannot clear the rendering context of an invalid m_renderer.");
	SDL_SetRenderDrawColor(m_renderer.get(), color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer.get());
}

void sonic::display::renderer::draw(sonic::resource::texture& texture, int dst_x, int dst_y, double angle, SDL_Rect * clip, SDL_Point * center, SDL_RendererFlip flip) noexcept
{
	assert(m_renderer && "Cannot render a texture with an invalid m_renderer.");
	assert(texture && "Cannot render an invalid texture");
	SDL_Rect render_dst = { dst_x,  dst_y, texture.width(), texture.height() };
	if (clip) {
		render_dst.w = clip->w;
		render_dst.h = clip->h;
	}
	SDL_RenderCopyEx(this->m_renderer.get(), texture, clip, &render_dst, angle, center, flip);
}

void sonic::display::renderer::display() noexcept
{
	assert(m_renderer && "renderer is invalid");
	SDL_RenderPresent(this->m_renderer.get());
}

bool sonic::display::operator==(const sonic::display::renderer & a, const sonic::display::renderer & b) noexcept
{
	return a.window_id() == b.window_id();
}

bool sonic::display::operator!=(const sonic::display::renderer & a, const sonic::display::renderer & b) noexcept
{
	return !(a == b);
}
