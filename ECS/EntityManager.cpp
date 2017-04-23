#include "EntityManager.hpp"
#include "Entity.hpp"

EntityManager::EntityManager(void)
{
}

EntityManager::~EntityManager(void)
{
	entities_.clear();
	components_.clear();
	componentsBits_.clear();
}

void EntityManager::createEntity(Entity id)
{
	entities_.insert(id);
}

void EntityManager::deleteEntity(Entity entityId)
{
	std::clog << "deleting entity #" << entityId << std::endl;
	entities_.erase(entityId);
	components_.erase(entityId);
	componentsBits_.erase(entityId);
}

std::set<Entity> const& EntityManager::getEntities(void) const
{
	return entities_;
}