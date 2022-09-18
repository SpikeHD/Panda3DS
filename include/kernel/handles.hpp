#pragma once
#include "helpers.hpp"

using Handle = u32;

namespace KernelHandles {
	enum : u32 {
		Max = 0xFFFF7FFF, // Max handle the kernel can automagically allocate

		// Hardcoded handles
		CurrentThread = 0xFFFF8000,  // Used by the original kernel
		CurrentProcess = 0xFFFF8001, // Used by the original kernel
		APT = 0xFFFF8002,            // App Title something service?
		HID = 0xFFFF8003,            // Handles everything input-related including gyro
		FS  = 0xFFFF8004,            // Filesystem service

		MinServiceHandle = APT,
		MaxServiceHandle = FS
	};

	// Returns whether "handle" belongs to one of the OS services
	static constexpr bool isServiceHandle(Handle handle) {
		return handle >= MinServiceHandle && handle <= MaxServiceHandle;
	}

	// Returns the name of a handle as a string based on the given handle
	static const char* getServiceName(Handle handle) {
		switch (handle) {
			case APT: return "APT";
			case HID: return "HID";
			case FS: return "FS";
			default: return "Unknown";
		}
	}
}