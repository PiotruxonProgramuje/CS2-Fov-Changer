#include "gui.h"
#include "mem.h"
#include "globals.h"
#include "hacks.h"
#include <thread>

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{
	const auto mem = Memory("cs2.exe");

	globals::client = mem.GetModuleAddress("client.dll");

	std::thread(hacks::MiscThread, mem).detach();
	std::thread(hacks::VisualThread, mem).detach();
	std::thread(hacks::AimThread, mem).detach();

	// create gui
	gui::CreateHWindow("Cheat Menu");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::isRunning)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	// destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}
