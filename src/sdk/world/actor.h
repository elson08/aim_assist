#pragma once

#include "aabb.h"
#include "built_in_actor_components.h"
#include "sdk/entity/components/aabb_shape_component.h"
#include "sdk/entity/components/offsets_component.h"
#include "sdk/entity/components/render_position_component.h"
#include "sdk/entity/entity_context.h"

class Actor {
public:
	[[nodiscard]] decltype(auto) getEntityContext(this auto&& self) {
		return hat::member_at<EntityContext>(std::addressof(self), 0x8);
	}

	[[nodiscard]] decltype(auto) getBuiltInActorComponents(this auto&& self) {
		return hat::member_at<BuiltInActorComponents>(std::addressof(self), 0x218);
	}

	[[nodiscard]] std::optional<glm::vec3> getRenderPosition() const {
		if (const auto* component = getEntityContext().tryGet<RenderPositionComponent>()) {
			return component->mValue;
		}

		return std::nullopt;
	}
};
