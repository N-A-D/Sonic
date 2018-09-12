#include "sonic_resource_font.h"

sonic::resource::font::font() : m_font(nullptr), filename("")
{
}

sonic::resource::font::font(const std::string& path, int font_size)
	: m_font(std::shared_ptr<TTF_Font>(TTF_OpenFont(path.c_str(), font_size), [](TTF_Font* f) { TTF_CloseFont(f); })), filename(path)
{
	if (!m_font)
		throw std::runtime_error("Could not load font from path: " + path + " -- " + TTF_GetError());
}

int sonic::resource::font::font_style() const noexcept
{
	assert(m_font && "Cannot get the style of an invalid font.");
	return TTF_GetFontStyle(m_font.get());
}

void sonic::resource::font::set_font_style(int style) noexcept
{
	assert(m_font && "Cannot set the style of an invalid font.");
	TTF_SetFontStyle(m_font.get(), style);
}

int sonic::resource::font::font_outline() const noexcept
{
	assert(m_font && "Cannot get the outline of an invalid font.");
	return TTF_GetFontOutline(m_font.get());
}

void sonic::resource::font::set_font_outline(int outline_size) noexcept
{
	assert(m_font && "Cannot set the outline of an invalid font.");
	TTF_SetFontOutline(m_font.get(), outline_size);
}

int sonic::resource::font::font_height() const noexcept
{
	assert(m_font && "Cannot get the height of an invalid font.");
	return TTF_FontHeight(m_font.get());
}

void sonic::resource::font::resize(int new_size) noexcept
{
	assert(filename != "");
	m_font.reset(TTF_OpenFont(filename.c_str(), new_size), [](TTF_Font* f) { TTF_CloseFont(f); });
}

sonic::resource::font::operator TTF_Font*() const noexcept
{
	return m_font.get();
}

sonic::resource::font::operator bool() const noexcept
{
	return m_font.get() != nullptr;
}