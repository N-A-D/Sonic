#pragma once

#include <SDL.h>
#include <array>
#include <string>
#include <memory>
#include <stdint.h>
#include <SDL_ttf.h>

namespace sonic {
	namespace resource {
		class texture;
	}
}

namespace sonic {
	namespace display {

		class window;

		class renderer final {
		public:
			renderer();

			// Checks if this renderer is valid
			operator bool() const noexcept;

			// Gets the window id that created this display::renderer
			std::uint32_t window_id() const noexcept;

			// Converts this Renderer to an SDL_Renderer*
			operator SDL_Renderer*() const noexcept;

			// Sets the viewport for this display::renderer
			// example:
			// renderer.set_viewport({ 128, 128, 64, 64 });
			void set_viewport(const SDL_Rect& rect) noexcept;

			// Sets the color used for drawing ops 
			// example:
			// renderer.set_draw_color({ 255, 0, 0, 128 });
			void set_draw_color(const SDL_Color& color) noexcept;

			// Gets the draw color of this display::renderer
			// where the integers specify the R, G, B, and A values 
			//SDL_Color draw_colors = renderer.draw_colors();
			SDL_Color draw_color() const noexcept;

			// Draws a colored line
			// Note: the first two integers are make up the starting point while the last two
			// integers make up the end point
			// example:
			// renderer.draw_line({0, 0, 10, 10});
			void draw_line(const std::array<int, 4>& points) noexcept;

			// Draws multiple lines given by the sequence from begin to end
			// example:
			// std::vector<std::array<int, 4>> lines;
			// lines.push_back({ 0, 0, 10, 10 });
			// lines.push_back({ 2, 2, 12, 12 });
			// lines.push_back({ 4, 4, 14, 14 });
			// renderer.draw_lines(lines.begin(), lines.end());
			template <class In>
			void draw_lines(In begin, In end) noexcept;

			// Draws a point
			// example:
			// renderer.draw_point({ 15, 15 });
			void draw_point(const SDL_Point& point) noexcept;

			// Draws multiple points given by the sequence from begin to end
			// example:
			// std::vector<SDL_Point> points;
			// points.push_back({ 15, 15 });
			// points.push_back({ 30, 30 });
			// points.push_back({ 45, 45 });
			// renderer.draw_points(points.begin(), points.end());
			template <class In>
			void draw_points(In begin, In end) noexcept;

			// Draws a rectangle outline
			// example:
			// renderer.draw_rectangle({ 100, 100, 20, 20 });
			void draw_rectangle(const SDL_Rect& rect) noexcept;

			// Draws multple rectangles given by the sequence from begin to end
			// example:
			// std::vector<SDL_Rect> rects;
			// rects.push_back({ 10, 10, 20, 20 });
			// rects.push_back({ 40, 10, 20, 20 });
			// rects.push_back({ 70, 10, 20, 20 });
			// renderer.draw_rectangles(rects.begin(), rects.end());
			template <class In>
			void draw_rectangles(In begin, In end) noexcept;

			// Draws a filled rectangle
			// example:
			// renderer.draw_filled_rectangle({ 10, 10, 20, 20 });
			void draw_filled_rectangle(const SDL_Rect& rect) noexcept;

			// Draws multiple filled rectangles
			// example:
			// std::vector<SDL_Rect> filled_rects;
			// filled_rects.push_back({ 10, 10, 20, 20 });
			// filled_rects.push_back({ 40, 10, 20, 20 });
			// filled_rects.push_back({ 70, 10, 20, 20 });
			// renderer.draw_filled_rectangles(filled_rects.begin(), filled_rects.end());
			template <class In>
			void draw_filled_rectangles(In begin, In end) noexcept;

			// Clear the rendering target with the given color
			void clear(const SDL_Color& color = { 0, 0, 0, 0 }) noexcept;

			// Renders a texture onto the target
			void draw(sonic::resource::texture& texture, int dst_x, int dst_y, double angle = 0.0,
				SDL_Rect* clip = nullptr, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) noexcept;

			// Displays what has been rendered to the screen
			void display() noexcept;

		private:
			friend class window;

			// Only a window may create a renderer
			renderer(SDL_Renderer* r, std::uint32_t window_id);

			// The internally managed SDL_Renderer
			std::shared_ptr<SDL_Renderer> m_renderer;

			// The Window that created this renderer
			std::uint32_t w_id;
		};

		bool operator==(const sonic::display::renderer& a, const sonic::display::renderer& b) noexcept;
		bool operator!=(const sonic::display::renderer& a, const sonic::display::renderer& b) noexcept;

		template<class In>
		inline void renderer::draw_lines(In begin, In end) noexcept
		{
			for (In i = begin; i != end; ++i)
				draw_line(*i);
		}

		template<class In>
		inline void renderer::draw_points(In begin, In end) noexcept
		{
			for (In i = begin; i != end; ++i)
				draw_point(*i);
		}

		template<class In>
		inline void renderer::draw_rectangles(In begin, In end) noexcept
		{
			for (In i = begin; i != end; ++i)
				draw_rectangle(*i);
		}

		template<class In>
		inline void renderer::draw_filled_rectangles(In begin, In end) noexcept
		{
			for (In i = begin; i != end; ++i)
				draw_filled_rectangle(*i);
		}
	}
}
