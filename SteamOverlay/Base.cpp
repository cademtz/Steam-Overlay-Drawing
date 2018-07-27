#include "Base.h"
#include "CSignature.h"
#include "OverlayHooks.h"
#include "CDraw.h"

CBaseManager gBase;
CDrawManager* gDraw = nullptr;

bool CBaseManager::GetOffsets()
{
	SafePointer present = gSignatures.GetSignature("gameoverlayrenderer.dll", "FF 15 ?? ?? ?? ?? 8B F8 85 DB");
	SafePointer reset = gSignatures.GetSignature("gameoverlayrenderer.dll", "FF 15 ? ? ? ? 8B F8 85 FF 78 18");
	dwPresent = present.Pointer + 0x2, dwReset = reset.Pointer + 0x2; // Offsets the call opcode to get the function location

	return true;
}

bool CBaseManager::Hook()
{
	if (!dwPresent || !dwReset)
		return Fatal("Could not hook: Missing required offsets");

	original_present = **(decltype(&original_present)*)(dwPresent);
	original_reset = **(decltype(&original_reset)*)(dwReset);

	**(void***)(dwPresent) = (void*)(&present);
	**(void***)(dwReset) = (void*)(&reset);

	return true;
}

bool CBaseManager::Fatal(const char* szMessage)
{
	char buffer[256];
	sprintf_s(buffer, "%s\nThe process will now exit.", szMessage);
	MessageBox(NULL, buffer, "Fatal error", MB_OK);
	DebugBreak();
	exit(0);
	return false;
}

DWORD CBaseManager::SafePointer::NullptrCheck(DWORD dwOffset)
{
	if (dwOffset)
		return dwOffset;

	return gBase.Fatal("Failed to get a required offset.");
}