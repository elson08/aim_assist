#pragma once

class Timer {
public:
	Timer() : mPrevious(std::chrono::steady_clock::now()) { }

	[[nodiscard]] float deltaTime() {
		const auto now = std::chrono::steady_clock::now();
		const float deltaTime = glm::clamp(std::chrono::duration<float>(now - mPrevious).count(), 0.0f, 0.1f);
		mPrevious = now;
		return deltaTime;
	}

private:
	std::chrono::steady_clock::time_point mPrevious;
};
