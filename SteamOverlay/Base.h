#pragma once
#include <Windows.h>
#include <string>

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

using namespace std;
class CDrawManager;

class CBaseManager
{
public:
	bool GetOffsets();
	bool Hook();
	//bool Unhook(); !! Not implemented yet !!

	// - Creates a messagebox with the specified error message and closes the process
	// - Return value is always false
	bool Fatal(const char* szMessage);
private:
	struct SafePointer
	{
		DWORD Pointer;
		SafePointer(DWORD dwPointer) { Pointer = NullptrCheck(dwPointer); }
		DWORD NullptrCheck(DWORD dwOffset);
	};
	DWORD dwPresent = NULL;
	DWORD dwReset = NULL;
};
extern CBaseManager gBase;
extern CDrawManager* gDraw;