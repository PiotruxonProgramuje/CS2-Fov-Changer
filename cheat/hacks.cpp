#include "hacks.h"
#include "gui.h"
#include "globals.h"

#include <thread>

void hacks::MiscThread(const Memory& mem) noexcept
{
	while (gui::isRunning)
	{
		std::uint16_t desiredFov = (uint16_t)globals::FOV;
		std::uintptr_t localPlayer = mem.Read<std::uintptr_t>(globals::client + offsets::dwLocalPlayerPawn);

		std::uintptr_t CameraServices = mem.Read<std::uintptr_t>(localPlayer + offsets::m_pCameraServices);

		std::uint16_t currentFov = mem.Read<std::uint16_t>(CameraServices + offsets::m_iFOV);

		bool isScoped = mem.Read<bool>(localPlayer + offsets::m_bIsScoped);

		if (!isScoped && currentFov != desiredFov)
		{
			mem.Write<uint64_t>(CameraServices + offsets::m_iFOV, desiredFov);
		}
			
	}
}

void hacks::VisualThread(const Memory& mem) noexcept
{
	while (gui::isRunning)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void hacks::AimThread(const Memory& mem) noexcept
{
	while (gui::isRunning)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}