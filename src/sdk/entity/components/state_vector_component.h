#pragma once

#include "sdk/entity/entity_id_traits.h"

struct StateVectorComponent : EntityComponent {
	glm::vec3 mPosition;
	glm::vec3 mPreviousPosition;
	glm::vec3 mPositionDelta;
};
