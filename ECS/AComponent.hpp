#pragma once

#include <iostream>
#include <memory>

#include "Constants.hpp"
#include "Entity.hpp"

namespace Component
{
	using ComponentID = int;

	inline ComponentID getUniqueComponentID(void)
	{
		static ComponentID lastID { 0u };
		return lastID++;
	}

	template <typename T>
	inline ComponentID getComponentTypeID(void)
	{
		static ComponentID typeID { getUniqueComponentID() };
		return typeID;
	}

	struct AComponent : public std::enable_shared_from_this<AComponent>
	{
		AComponent(void) { parent = nullptr; }
		virtual ~AComponent(void) { std::cout << "deleting component" << std::endl; }
		
		Entity *parent;
	};
}