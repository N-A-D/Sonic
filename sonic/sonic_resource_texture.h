#pragma once

#include <string>
#include <memory>
#include <stdint.h>
#include <SDL_image.h>
#include "sonic_resource.h"

namespace sonic {
	namespace display {
		class renderer;
	}
}

namespace sonic {
	namespace resource {

		class font;

		// The texture class
		// Is the base for the following classes: 
		// resource::image
		// resource::text
		// resource::shaded_text
	    // resource::blended_text
		// 
		// The class cannot be used explicitly but is used implicitly
		// through the use of the aforementioned classes
		class texture {
		public:

			// Constructs a new texture
			texture();

			// Gets the width of the texture
			int width() const noexcept;

			// Gets the height of the texture
			int height() const noexcept;

			// Gets the format of this texture
			std::uint32_t format() const noexcept;

			// Converts this Texture to an SDL_Texture*
			operator SDL_Texture*() const noexcept;

			// Checks if this texture is valid
			operator bool() const noexcept;

			// Modulates the Texture's colors
			void color_mod(const SDL_Color& color) noexcept;

			// Sets the blending mode for this texture
			// This controls how the texture is blended
			void blend_mode(SDL_BlendMode mode) noexcept;

			// Modifies the Texture's alpha modulation
			// This controls the transparency of a texture
			void alpha_mod(std::uint8_t alpha_value) noexcept;

		protected:

			// Construct a new texture from an SDL_Texture
			explicit texture(SDL_Texture* t);

		private:
			// Internally managed SDL texture
			std::shared_ptr<SDL_Texture> m_texture;

			// Texture specific vars
			int w;
			int h;
			std::uint32_t texture_format;

		};
		
		// A texture loaded from an image file
		class image final : public texture, public sonic::resource::resource_type<image> {
		public:
			image() {}
			image(sonic::display::renderer& renderer, const std::string& path);
		private:
			SDL_Texture * load_image(sonic::display::renderer& renderer, const std::string& path) const;
		};

		// Solid rendered text
		class text final : public texture, public sonic::resource::resource_type<text> {
		public:
			text() {}
			text(sonic::display::renderer& renderer, // The text renderer
				 sonic::resource::font& font,        // The font used for creating the rendered text
				 const std::string& text,            // The text 
				 const SDL_Color& text_color);       // The text color
		private:
			SDL_Texture * load_solid_text(sonic::display::renderer& renderer,
				sonic::resource::font& font,
				const std::string& text,
				const SDL_Color& text_color) const;
		};

		// Shaded rendered text
		class shaded_text final : public texture, public sonic::resource::resource_type<shaded_text> {
		public:
			shaded_text() {}
			shaded_text(sonic::display::renderer& renderer, // The text renderer
				        sonic::resource::font& font,        // The font used for creating the rendered text
				        const std::string& text,            // The text 
				        const SDL_Color& text_color,        // The color of the text
			            const SDL_Color& bg_color);         // The background color
		private:
			SDL_Texture * load_shaded_text(sonic::display::renderer& renderer,
				sonic::resource::font& font,
				const std::string& text,
				const SDL_Color& text_color,
				const SDL_Color& bg_color) const;
		};

		// Blended rendered text
		class blended_text final : public texture, public sonic::resource::resource_type<shaded_text> {
		public:
			blended_text() {}
			blended_text(sonic::display::renderer& renderer, // The text renderer
				sonic::resource::font& font,                 // The font used for creating the rendered text
				const std::string& text,                     // The text 
				const SDL_Color& text_color);                // The text color
		private:
			SDL_Texture* load_blended_text(sonic::display::renderer& renderer,
				sonic::resource::font& font,
				const std::string& text,
				const SDL_Color& text_color) const;
		};
	}
}