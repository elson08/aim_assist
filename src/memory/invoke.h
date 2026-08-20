#pragma once

namespace memory {
	namespace detail {
		template <typename>
		struct member_fn;

		template <typename Return, typename Class, typename... Args>
		struct member_fn<Return (Class::*)(Args...)> : std::type_identity<Return (*)(Class*, Args...)> { };

		template <typename Return, typename Class, typename... Args>
		struct member_fn<Return (Class::*)(Args...) const> : std::type_identity<Return (*)(const Class*, Args...)> { };
	}

	template <typename Fn, typename Class, typename... Args>
	decltype(auto) invokeMember(const uintptr_t address, Class* instance, Args&&... args) {
		const auto fn = reinterpret_cast<typename detail::member_fn<Fn>::type>(address);
		return fn(instance, std::forward<Args>(args)...);
	}

	template <size_t I, typename Fn, typename Class, typename... Args>
	decltype(auto) invokeVirtual(Class* instance, Args&&... args) {
		const auto vtable = *reinterpret_cast<uintptr_t* const*>(instance);
		return invokeMember<Fn>(vtable[I], instance, std::forward<Args>(args)...);
	}
}
