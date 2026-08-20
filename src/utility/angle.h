#pragma once

namespace angle {
	[[nodiscard]] inline glm::vec2 between(const glm::vec3& from, const glm::vec3& to) {
		const glm::vec3 direction = to - from;
		const float horizontal = std::hypot(direction.x, direction.z);
		return glm::degrees(glm::vec2{
			-std::atan2(direction.y, horizontal),
			std::atan2(-direction.x, direction.z)
		});
	}

	[[nodiscard]] inline glm::vec2 delta(const glm::vec2& current, const glm::vec2& desired) {
		return {
			desired.x - current.x,
			std::remainder(desired.y - current.y, 360.0f)
		};
	}

	[[nodiscard]] inline glm::vec2 turnDelta(const glm::vec3& from, const glm::vec3& to, const glm::vec2& current) {
		return delta(current, between(from, to));
	}

	[[nodiscard]] inline glm::vec2 lerp(const glm::vec2& delta, const float amount) {
		return delta * glm::clamp(amount, 0.0f, 1.0f);
	}
}
