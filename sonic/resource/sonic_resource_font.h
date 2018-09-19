#pragma once

#include <string>
#include <memory>
#include <SDL_ttf.h>
#include "sonic_resource.h"

namespace sonic {
	namespace resource {

		// Font class
		// Used for writing text onto a screen
		class font final : public sonic::resource::resource_t<font> {
		public:

			// Constructors
			font();
			font(const std::string& path, int font_size);

			// Conversion to a TTF_Font pointer
			operator TTF_Font*() const noexcept;

			// Checks if this font is initialized correctly
			operator bool() const noexcept;

			// Returns the this font's style
			// The returned style is a bitmask composed of the following:
			// TTF_STYLE_BOLD
			// TTF_STYLE_ITALIC
			// TTF_STYLE_UNDERLINE
			// TTF_STYLE_STRIKETHROUGH
			// If a style was not set, then TTF_NORMAL_STYLE will be returned
			int font_style() const noexcept;

			// Sets this font's style
			// the style parameter is a bitmask composed of:
			// TTF_STYLE_BOLD
			// TTF_STYLE_ITALIC
			// TTF_STYLE_UNDERLINE
			// TTF_STYLE_STRIKETHROUGH
			void set_font_style(int style) noexcept;

			// Returns the current size of the font's outline
			int font_outline() const noexcept;

			// Sets the font's outline size
			// Passing in zero will remove outlines on the font
			void set_font_outline(int outline_size) noexcept;

			// Returns the maximum height of all glyphs using this font.
			// This may be used for rendering text such that they are close 
			// together vertically as possible. 
			int font_height() const noexcept;

			// Resizes the font
			void resize(int new_size) noexcept;

		private:
			std::string filename;
			std::shared_ptr<TTF_Font> m_font;
		};

	}
}