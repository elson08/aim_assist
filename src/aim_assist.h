#pragma once

#include "sdk/entity/components/rotation_component.h"
#include "sdk/game/minecraft_game.h"
#include "sdk/world/local_player.h"
#include "utility/angle.h"
#include "utility/target.h"
#include "utility/timer.h"

namespace aim_assist {
    inline void run(MinecraftGame& game) {
        static Timer timer{};

        const auto& client = game.getPrimaryClientInstance();
        if (!client) {
            return;
        }

        auto* player = client->getLocalPlayer();
        if (player == nullptr) {
            return;
        }

        const auto playerPosition = player->getRenderPosition();
        if (!playerPosition) {
            return;
        }

        const auto* selectedTarget = target::bestDistance(player->getEntityContext().mEnttRegistry, playerPosition.value(), 100.0f);
        if (!selectedTarget) {
            return;
        }

        const auto targetPosition = selectedTarget->getRenderPosition();
        if (!targetPosition) {
            return;
        }

        const auto current = player->getBuiltInActorComponents().mRotationComponent->mRotation;
        const auto totalTurnDelta = angle::turnDelta(playerPosition.value(), targetPosition.value(), current);
        const auto k = 1.0f - std::exp(-10.0f * timer.deltaTime());
        const auto turnDelta = angle::lerp(totalTurnDelta, k);
        player->applyTurnDelta({ 0, turnDelta.y });
    }
}
