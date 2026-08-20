#pragma once

#include "aim_assist.h"
#include "memory/signature_result.h"
#include "sdk/game/minecraft_game.h"

struct MinecraftGameHook {
	static inline safetyhook::InlineHook hook;

	static void detour(MinecraftGame* self) {
		aim_assist::run(*self);
		hook.call(self);
	}

	[[nodiscard]] static bool install() {
		const auto& result = memory::signature_result_v<&MinecraftGame::update>;
		if (!result.has_result()) {
			return false;
		}

		hook = safetyhook::create_inline(result.get(), detour);
		return static_cast<bool>(hook);
	}
};

[[nodiscard]] inline bool installHooks() {
	return MinecraftGameHook::install();
}
