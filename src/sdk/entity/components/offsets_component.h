#pragma once

#include "sdk/entity/entity_id_traits.h"

struct OffsetsComponent : EntityComponent {
	float mHeightOffset;
	float mExplosionOffset;
	glm::vec3 mHeadOffset;
	glm::vec3 mDropOffset;
	glm::vec3 mEyeOffset;
	glm::vec3 mMouthOffset;
	glm::vec3 mBreathingOffset;
};
