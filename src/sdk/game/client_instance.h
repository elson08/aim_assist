#pragma once

#include "memory/invoke.h"

class LocalPlayer;

class ClientInstance {
public:
	[[nodiscard]] LocalPlayer* getLocalPlayer() const {
		return memory::invokeVirtual<31, decltype(&ClientInstance::getLocalPlayer)>(this);
	}
};
