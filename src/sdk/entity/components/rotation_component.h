#pragma once

#include "sdk/entity/entity_id_traits.h"

struct ActorRotationComponent : EntityComponent {
	glm::vec2 mRotation;
	glm::vec2 mPrevRotation;
};
