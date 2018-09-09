#include <fstream>
#include <cassert>
#include <rapidxml_utils.hpp>
#include "sonic_resource_spritesheet.h"

sonic::resource::sprite_sheet::sprite_sheet(sonic::display::renderer renderer, const std::string & xml_path)
{
	load_data(renderer, xml_path);
}

sonic::resource::sprite_sheet::operator bool() const noexcept
{
	return this->ss_img;;
}

sonic::resource::texture sonic::resource::sprite_sheet::texture() noexcept
{
	return this->ss_img;
}

SDL_Rect sonic::resource::sprite_sheet::get(std::string subtexture_name) const noexcept
{
	assert(subtexture_data.find(subtexture_name) != subtexture_data.end());
	return subtexture_data.at(subtexture_name);
}

void sonic::resource::sprite_sheet::load_data(sonic::display::renderer renderer, const std::string& xml_data)
{
	std::fstream data(xml_data);

	std::vector<char> buffer((std::istreambuf_iterator<char>(data)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');

	rapidxml::xml_document<> doc;
	doc.parse<0>(&buffer[0]);
	auto node = doc.first_node();

	// Initialize the spritesheet texture and the spritesheet name
	for (auto attr = node->first_attribute(); attr; attr = attr->next_attribute()) {
		if (strcmp(attr->name(), "imagePath") == 0) {
			this->ss_img = sonic::resource::image(renderer, attr->value());
		}
	}

	assert(this->ss_img);

	// Load all of the subtexture data
	for (auto child = node->first_node(); child; child = child->next_sibling()) {

		// Temporary vars
		std::string subtexture_name;
		SDL_Rect r;

		// Attributes contain the data for each subtexture
		for (auto attr = child->first_attribute(); attr; attr = attr->next_attribute()) {
			if (strcmp(attr->name(), "name") == 0) {
				subtexture_name = std::string(attr->value());
			}
			else if (strcmp(attr->name(), "x") == 0) {
				r.x = atoi(attr->value());
			}
			else if (strcmp(attr->name(), "y") == 0) {
				r.y = atoi(attr->value());
			}
			else if (strcmp(attr->name(), "width") == 0) {
				r.w = atoi(attr->value());
			}
			else if (strcmp(attr->name(), "height") == 0) {
				r.h = atoi(attr->value());
			}
		}

		assert(r.w != 0 && r.h != 0 && "Subtexture rectangle is empty.");

		this->subtexture_data.insert(std::make_pair(subtexture_name, r));
	}
	assert(this->subtexture_data.size() != 0 && "There was no subtexture data to load.");
}