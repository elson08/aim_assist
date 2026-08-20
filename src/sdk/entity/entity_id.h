#pragma once

struct EntityID {
	using entity_type = uint32_t;

	uint32_t mRawId;

	[[nodiscard]] constexpr bool operator==(const EntityID&) const = default;
	[[nodiscard]] constexpr operator std::uint32_t() const {
		return mRawId;
	}
};
