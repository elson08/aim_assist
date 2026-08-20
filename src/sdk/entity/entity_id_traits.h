#pragma once

#include "entity_id.h"

struct EntityIDTraits {
	using value_type = EntityID;
	using entity_type = std::uint32_t;
	using version_type = std::uint16_t;

	static constexpr entity_type entity_mask = 0x3FFFF;
	static constexpr entity_type version_mask = 0x3FFF;
};

template <>
struct entt::entt_traits<EntityID> : basic_entt_traits<EntityIDTraits> {
	static constexpr entity_type page_size = 2048;
};

struct EntityComponent { };

template <std::derived_from<EntityComponent> Type>
struct entt::component_traits<Type, EntityID> {
	using element_type = Type;
	using entity_type = EntityID;
	static constexpr bool in_place_delete = true;
	static constexpr std::size_t page_size = 128 * !std::is_empty_v<Type>;
};

template <typename Type>
struct entt::storage_type<Type, EntityID> {
	using type = basic_storage<Type, EntityID>;
};
