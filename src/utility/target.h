#pragma once

#include "sdk/entity/components/actor_owner_component.h"
#include "sdk/entity/components/local_player_component.h"
#include "sdk/entity/components/player_component.h"

namespace target {
	void forEach(entt::basic_registry<EntityID>& registry, std::invocable<Actor*> auto&& callback) {
		const auto view = registry.view<ActorOwnerComponent, PlayerComponent>(entt::exclude<LocalPlayerComponent>);
		for (auto&& [entity, owner] : view.each()) {
			if (Actor* actor = owner.mActor.get()) {
				callback(actor);
			}
		}
	}

	[[nodiscard]] inline Actor* bestDistance(entt::basic_registry<EntityID>& registry, const glm::vec3& relative, const float maxDistSqr = std::numeric_limits<float>::max()) {
		Actor* bestActor = nullptr;
		float bestDist = maxDistSqr;

		forEach(registry, [&](Actor* actor) {
			const auto position = actor->getRenderPosition();
			if (!position) {
				return;
			}

			const glm::vec3 delta = position.value() - relative;
			if (const float distanceSquared = glm::dot(delta, delta); distanceSquared < bestDist) {
				bestDist = distanceSquared;
				bestActor = actor;
			}
		});

		return bestActor;
	}
}
