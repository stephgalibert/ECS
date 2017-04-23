#pragma once

#include <iostream>
#include <memory>

#include "Constants.hpp"
#include "Entity.hpp"

// generation d'un id de chaque component avec les templates ?
namespace Component
{
	struct AComponent : public std::enable_shared_from_this<AComponent>
	{
		AComponent(void) { parent = nullptr; }
		virtual ~AComponent(void) { std::cout << "deleting component" << std::endl; }
		
		Entity *parent;
	};
}