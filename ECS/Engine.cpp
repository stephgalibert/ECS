#include "Engine.hpp"

Engine::Engine(void)
	: renderSystem_(entityManager_)
{
}

Engine::~Engine(void)
{
}

void Engine::draw(sf::RenderWindow &window)
{
	renderSystem_.render(window);
}

void Engine::update(float delta)
{
	//auto const& Entities = Manager::GetEntities();

	//for (auto it : Manager::GetEntities())
	//{
	//	// system.update(delta);
	//	// ...
	//}
}

// tmp
void Engine::createPlayer(int id)
{
	entityManager_.createEntity(id);

	std::unique_ptr<Component::Render> component(new Component::Render);
	component->setTexture("./rsrc/planes.png");

	entityManager_.addComponent<Component::Render>(id, std::move(component));
	//entityManager_.deleteComponent<Component::Render>(id);
	//entityManager_.deleteEntity(id);
}