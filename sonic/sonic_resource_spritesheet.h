#pragma once

#include <SDL.h>
#include <string>
#include <queue>
#include <unordered_map>
#include "sonic_resource.h"
#include "sonic_resource_texture.h"
#include "sonic_display_renderer.h"

namespace sonic {
	namespace resource {

		// The sprite_sheet class
		// Contains the spritesheet image texture and the data of each sub-image texture
		class sprite_sheet : public sonic::resource::resource_t<sprite_sheet> {
		public:

			// Used for intializing a single spritesheet
			// where the xml file contains only data for the one sheet
			sprite_sheet(sonic::display::renderer renderer, // The renderer that loads the spritesheet texture
				         const std::string& xml_path);      // The xml data on the image file name as well as subtexture information   

			operator bool() const noexcept;

			// Returns the spritesheet texture
			sonic::resource::texture texture() const noexcept;

			// Returns the subtextue data linked to the given subtexture_name
			// Note: an assertion is made for the existence of a subtexture image named 
			// subtexture_name
			SDL_Rect get(std::string subtexture_name) const noexcept;

		private:

			// Loads the texture and its subtexture data
			void load_data(sonic::display::renderer, const std::string& xml_data);

			// The main texture that contains all of the sprites
			sonic::resource::image ss_img;

			// The subtexture information
			// Contains the names of each subtexture. As well as the 
			// location and dimensions of the subtexture
			std::unordered_map<std::string, SDL_Rect> subtexture_data;

		};

	}
}