#pragma once

#include "signature.h"

namespace memory {
	namespace detail {
		template <typename Signature>
		struct signature_function;

		template <auto Fn>
		struct signature_function<Signature<Fn>> {
			static constexpr auto value = Fn;
		};

		template <typename Signature>
		inline constexpr auto signature_function_v = signature_function<Signature>::value;

		template <typename Signature>
		void scan_signature() {
			constexpr auto pattern = hat::compile_signature<Signature::pattern>();
			signature_result_v<signature_function_v<Signature>> = hat::find_pattern(pattern, ".text");
		}

		template <std::size_t... Indices>
		void scan_all(std::index_sequence<Indices...>) {
			(scan_signature<std::tuple_element_t<Indices, signatures>>(), ...);
		}
	}

	static void scanAll() {
		detail::scan_all(std::make_index_sequence<std::tuple_size_v<signatures>>{});
	}
}
