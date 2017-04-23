#pragma once

#include <iostream>
#include <set>
#include <unordered_map>
#include <memory>
#include <utility>
#include <bitset>
#include <array>

#include "AComponent.hpp"
#include "Entity.hpp"

class EntityManager
{
public:
	EntityManager(void);
	~EntityManager(void);

	void createEntity(Entity id);
	void deleteEntity(Entity entityId);

	std::set<Entity> const& getEntities(void) const;

	template <typename T>
	void addComponent(Entity entityId, std::unique_ptr<Component::AComponent> component);

	template <typename T>
	void deleteComponent(Entity entityId);

	template <typename T>
	bool hasComponent(Entity entityId) const;

	template <typename T>
	T *getComponent(Entity entityId) const;

private:
	std::set<Entity> entities_;
	std::unordered_map<Entity, std::array<std::unique_ptr<Component::AComponent>, Constants::MaximumComponent> > components_;
	std::unordered_map<Entity, std::bitset<Constants::MaximumComponent> > componentsBits_;
};

template <typename T>
void EntityManager::addComponent(Entity entityId, std::unique_ptr<Component::AComponent> component)
{
	components_[entityId][Component::getComponentTypeID<T>()] = std::move(component);
	componentsBits_[entityId][Component::getComponentTypeID<T>()] = true;
}

template <typename T>
void EntityManager::deleteComponent(Entity entityId)
{
	components_[entityId][Component::getComponentTypeID<T>()].reset();
	componentsBits_[entityId][Component::getComponentTypeID<T>()] = false;
}

template <typename T>
bool EntityManager::hasComponent(Entity entityId) const
{
	return componentsBits_.at(entityId)[Component::getComponentTypeID<T>()];
}

template <typename T>
T *EntityManager::getComponent(Entity entityId) const
{
	return static_cast<T *>(components_.at(entityId)[Component::getComponentTypeID<T>()].get());
}