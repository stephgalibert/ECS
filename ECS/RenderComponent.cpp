#include "RenderComponent.hpp"

Component::Render::Render(void)
{
}

Component::Render::~Render(void)
{
}

void Component::Render::setTexture(std::string const& path)
{
	if (!texture_.loadFromFile(path)) {
		throw std::runtime_error("setTexture: Unable to find " + path);
	}
	sprite_.setTexture(texture_);
}

sf::Sprite &Component::Render::getSprite(void)
{
	return (sprite_);
}