#include "hook/hooks.h"
#include "memory/scanner.h"

static DWORD WINAPI setup(LPVOID) {
	memory::scanAll();
	if (!installHooks()) {
		MessageBoxA(nullptr, "Failed to install hooks.", "Aim Assist", MB_ICONERROR);
		return 1;
	}

	MessageBoxA(nullptr, "Initialized successfully.", "Aim Assist", MB_ICONINFORMATION);
	return 0;
}

BOOL APIENTRY DllMain(const HMODULE module, const DWORD reason, LPVOID) {
	if (reason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(module);
		if (const HANDLE thread = CreateThread(nullptr, 0, setup, nullptr, 0, nullptr)) {
			CloseHandle(thread);
		}
	}

	return TRUE;
}
