#pragma once
#include "mem.h"

namespace hacks
{
	void MiscThread(const Memory& mem) noexcept;

	void VisualThread(const Memory& mem) noexcept;

	void AimThread(const Memory& mem) noexcept;
}
