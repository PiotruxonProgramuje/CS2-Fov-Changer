#pragma once
#include <cstddef>
#include <cstdint>
namespace offsets
{
	// offsets.hpp
	constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x1855CE8;
	// client_dll.hpp
	constexpr std::ptrdiff_t m_pCameraServices = 0x11E0;
	constexpr std::ptrdiff_t m_iFOV = 0x210;
	constexpr std::ptrdiff_t m_bIsScoped = 0x23E8;
}

namespace globals
{
	inline int FOV = 90;
	inline std::uintptr_t client = 0;
}