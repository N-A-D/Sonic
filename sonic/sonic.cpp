#include "sonic.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

void sonic::init() noexcept
{
	// Initializes SDL and its subsystems 
	if (SDL_Init(0)) {
		// Add logging here. Note use SDL_GetError()
	}

	// Initialize everything related to video
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
		// Add logging here. Note use SDL_GetError()
	}
	else {
		// Initialize SDL_image for png loading
		int img_flags = IMG_INIT_PNG;
		if (!(IMG_Init(img_flags) & img_flags)) {
			// Add logging here. Note use IMG_GetError()
		}

		// Initialize SDL_ttf
		if (TTF_Init() == -1) {
			// Add logging here. Note use TTF_GetError()
		}
	}

	// Initialize everything related to audio
	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
		// Add logging here. Note use SDL_GetError()
	}
	else {

		int mix_flags = MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC;

		if (!(Mix_Init(mix_flags) < 0)) {
			// Add logging here. Noe use Mix_GetError()
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			// Add logging here. Note use Mix_GetError()
		}

		// Reserve 8 channels (8 concurrent sounds playing at once)
		Mix_AllocateChannels(8);
	}
}

void sonic::close() noexcept
{
	Mix_AllocateChannels(0);
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
