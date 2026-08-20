#pragma once

namespace memory {
	template <auto Fn>
	struct SignatureResult {
		static inline hat::scan_result value;
	};

	template <auto Fn>
	inline auto& signature_result_v = SignatureResult<Fn>::value;
}
