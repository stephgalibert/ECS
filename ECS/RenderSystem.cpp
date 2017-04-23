#include "RenderSystem.hpp"

System::Render::Render(EntityManager &entityManager)
	:	manager_(entityManager)
{
}

System::Render::~Render(void)
{
}

void System::Render::render(sf::RenderWindow &window)
{
	window.clear();

	auto const& Entities = manager_.getEntities();
	std::clog << "rendering " << Entities.size() << " elements " << std::endl;

	for (auto const& entity : Entities) {
		if (manager_.hasComponent<Component::Render>(entity)) {
			Component::Render *c = manager_.getComponent<Component::Render>(entity);
			window.draw(c->getSprite());
		}
	}

	window.display();
}