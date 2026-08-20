#pragma once

#include "actor.h"
#include "memory/invoke.h"
#include "memory/signature_result.h"

class LocalPlayer : public Actor {
public:
	void applyTurnDelta(const glm::vec2& delta) {
		static const auto address = memory::signature_result_v<&LocalPlayer::applyTurnDelta>.rel(1);
		memory::invokeMember<decltype(&LocalPlayer::applyTurnDelta)>(reinterpret_cast<uintptr_t>(address), this, delta);
	}
};
