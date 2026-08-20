#pragma once

#include "entity_id_traits.h"

class EntityRegistry;

class EntityContext {
public:
	EntityRegistry& mRegistry;
	entt::basic_registry<EntityID>& mEnttRegistry;
	EntityID mEntity;

	template <std::derived_from<EntityComponent> Component>
	[[nodiscard]] Component* tryGet() {
		return mEnttRegistry.valid(mEntity) ? mEnttRegistry.try_get<Component>(mEntity) : nullptr;
	}

	template <std::derived_from<EntityComponent> Component>
	[[nodiscard]] const Component* tryGet() const {
		return mEnttRegistry.valid(mEntity) ? mEnttRegistry.try_get<Component>(mEntity) : nullptr;
	}
};
