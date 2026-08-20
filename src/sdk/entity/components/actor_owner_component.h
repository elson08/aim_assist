#pragma once

#include "sdk/entity/entity_id_traits.h"
#include "sdk/world/actor.h"

struct ActorOwnerComponent : EntityComponent {
	std::unique_ptr<Actor> mActor;
};
