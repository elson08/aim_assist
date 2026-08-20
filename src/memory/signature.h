#pragma once

#include "sdk/game/minecraft_game.h"
#include "sdk/world/local_player.h"

namespace memory {
	template <auto Fn>
	struct Signature;

	template <>
	struct Signature<&LocalPlayer::applyTurnDelta> {
		static constexpr auto pattern = hat::fixed_string{ "E8 ? ? ? ? 48 8B 4C 24 ? 48 31 E1 48 3B 0D ? ? ? ? 75 ? 0F 28 74 24 ? 0F 28 7C 24 ? 44 0F 28 44 24 ? 44 0F 28 4C 24 ? 48 83 C4" };
	};

	template <>
	struct Signature<&MinecraftGame::update> {
		static constexpr auto pattern = hat::fixed_string{ "55 41 56 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 48 C7 45 ? ? ? ? ? 48 89 CF 8B 05" };
	};

	using signatures = std::tuple<
		Signature<&LocalPlayer::applyTurnDelta>,
		Signature<&MinecraftGame::update>
	>;
}
