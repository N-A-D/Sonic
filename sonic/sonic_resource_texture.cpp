#include <assert.h>
#include <stdexcept>
#include "sonic_resource_font.h"
#include "sonic_display_renderer.h"
#include "sonic_resource_texture.h"

sonic::resource::texture::texture() : m_texture(nullptr), w(0), h(0), texture_format(0)
{
}

int sonic::resource::texture::width()
{
	return w;
}

int sonic::resource::texture::height()
{
	return h;
}

std::uint32_t sonic::resource::texture::format()
{
	return texture_format;
}

sonic::resource::texture::operator SDL_Texture*()
{
	assert(m_texture && "Cannot convert an invalid texture to SDL_Texture");
	return m_texture.get();
}

sonic::resource::texture::operator bool() const noexcept
{
	return m_texture.get() != nullptr;
}

void sonic::resource::texture::set_color_mod(const SDL_Color & color)
{
	assert(m_texture && "Cannot set the color mod of an invalid texture.");
	// Forward work onto SDL_SetTextureColorMod
	SDL_SetTextureColorMod(m_texture.get(), color.r, color.g, color.b);
}

void sonic::resource::texture::set_blend_mode(SDL_BlendMode mode)
{
	assert(m_texture && "Cannot set the blend mode of an invalid texture.");
	// Forward work onto SDL_SetTextureBlendMode
	SDL_SetTextureBlendMode(m_texture.get(), mode);
}

void sonic::resource::texture::set_alpha_mod(std::uint8_t alpha_value)
{
	assert(m_texture && "Cannot set the alpha mod of an invalid texture.");
	// Forward work onto SDL_SetTextureAlphaMod
	SDL_SetTextureAlphaMod(m_texture.get(), alpha_value);
}

sonic::resource::texture::texture(SDL_Texture * t)
	: m_texture(std::shared_ptr<SDL_Texture>(t, [](SDL_Texture* t) { SDL_DestroyTexture(t); }))
{
	SDL_QueryTexture(t, &texture_format, nullptr, &w, &h);
}

sonic::resource::image::image(sonic::display::renderer & renderer, const std::string & path)
	: sonic::resource::texture(load_image(renderer, path))
{
}

SDL_Texture * sonic::resource::image::load_image(sonic::display::renderer & renderer, const std::string & path) const
{
	assert(path != "" && "Cannot load a texture from an empty path");
	SDL_Texture* texture = nullptr;

	// Load the surface
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface)
		throw std::runtime_error("Could not load file from path: " + path + " -- " + IMG_GetError());

	// Convert the surface to a texture
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	// free the surface as its no longer needed
	SDL_FreeSurface(surface);

	if (!texture)
		throw std::runtime_error("Could not create texture from path: " + path + " -- " + IMG_GetError());

	return texture;
}

sonic::resource::text::text(sonic::display::renderer & renderer, sonic::resource::font & font, const std::string & text, const SDL_Color & text_color)
	: sonic::resource::texture(load_solid_text(renderer, font, text, text_color))
{
}

SDL_Texture * sonic::resource::text::load_solid_text(sonic::display::renderer & renderer, sonic::resource::font & font, const std::string & text, const SDL_Color & text_color) const
{
	assert(font && "Cannot render text with an invalid font.");

	// load the text as a surface
	auto surf = TTF_RenderText_Solid(font, text.c_str(), text_color);

	if (!surf)
		throw std::runtime_error("Could not load text: " + text + " -- " + IMG_GetError());

	// Convert the surface to a texture
	auto *texture = SDL_CreateTextureFromSurface(renderer, surf);

	// Free the surface
	SDL_FreeSurface(surf);

	if (!texture)
		throw std::runtime_error("Could not create texture for text: " + text + " -- " + IMG_GetError());

	return texture;
}

sonic::resource::shaded_text::shaded_text(sonic::display::renderer & renderer, sonic::resource::font & font, const std::string & text, const SDL_Color & text_color, const SDL_Color & bg_color)
: sonic::resource::texture(load_shaded_text(renderer, font, text, text_color, bg_color))
{
}

SDL_Texture * sonic::resource::shaded_text::load_shaded_text(sonic::display::renderer & renderer, sonic::resource::font & font, const std::string & text, const SDL_Color & text_color, const SDL_Color & bg_color) const
{
	assert(font && "Cannot render text with an invalid font.");

	// load the text as a surface
	auto surf = TTF_RenderText_Shaded(font, text.c_str(), text_color, bg_color);

	if (!surf)
		throw std::runtime_error("Could not load text: " + text + " -- " + IMG_GetError());

	// Convert the surface to a texture
	auto *texture = SDL_CreateTextureFromSurface(renderer, surf);

	// Free the surface
	SDL_FreeSurface(surf);

	if (!texture)
		throw std::runtime_error("Could not create texture for text: " + text + " -- " + IMG_GetError());

	return texture;
}

sonic::resource::blended_text::blended_text(sonic::display::renderer & renderer, sonic::resource::font & font, const std::string & text, const SDL_Color & text_color)
	: sonic::resource::texture(load_blended_text(renderer, font, text, text_color))
{
}

SDL_Texture * sonic::resource::blended_text::load_blended_text(sonic::display::renderer & renderer, sonic::resource::font & font, const std::string & text, const SDL_Color & text_color) const
{
	assert(font && "Cannot render text with an invalid font.");

	// load the text as a surface
	auto surf = TTF_RenderText_Blended(font, text.c_str(), text_color);

	if (!surf)
		throw std::runtime_error("Could not load text: " + text + " -- " + IMG_GetError());

	// Convert the surface to a texture
	auto *texture = SDL_CreateTextureFromSurface(renderer, surf);

	// Free the surface
	SDL_FreeSurface(surf);

	if (!texture)
		throw std::runtime_error("Could not create texture for text: " + text + " -- " + IMG_GetError());

	return texture;
}
