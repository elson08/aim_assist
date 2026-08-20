#pragma once

class AABB {
public:
	glm::vec3 min;
	glm::vec3 max;

	constexpr AABB() = default;
	constexpr AABB(const glm::vec3 min, const glm::vec3 max) : min(min), max(max) { }
};
