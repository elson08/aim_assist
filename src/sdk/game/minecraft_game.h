#pragma once

#include "sub_client_id.h"
#include "client_instance.h"

class MinecraftGame {
public:
	using ClientInstanceMap = std::map<SubClientID, std::shared_ptr<ClientInstance>>;

	void update();

	[[nodiscard]] decltype(auto) getClientInstances(this auto&& self) {
		return hat::member_at<ClientInstanceMap>(std::addressof(self), 0x938);
	}

	[[nodiscard]] decltype(auto) getPrimaryClientInstance(this auto&& self) {
		return self.getClientInstances().at(SubClientID::PrimaryClient);
	}
};
