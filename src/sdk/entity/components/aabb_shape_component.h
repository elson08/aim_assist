#pragma once

#include "sdk/entity/entity_id_traits.h"
#include "sdk/world/aabb.h"

struct AABBShapeComponent : EntityComponent {
	AABB mAABB;
	glm::vec2 mBBDim;
};
