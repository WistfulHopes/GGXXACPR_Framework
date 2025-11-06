#include "pch.h"
#include "GGFramework.h"
#include "Console.h"

auto init() -> void
{
	CreateConsole();
    GGFramework* framework = GGFramework::get_instance();
}

BOOL APIENTRY DllMain([[maybe_unused]] HMODULE Module,
                      DWORD ReasonForCall,
                      [[maybe_unused]] LPVOID Reserved)
{
    switch (ReasonForCall)
    {
    case DLL_PROCESS_ATTACH:
        init();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    default:
        break;
    }
    return TRUE;
}
