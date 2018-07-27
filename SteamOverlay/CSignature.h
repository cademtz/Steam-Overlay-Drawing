#pragma once
#include "Base.h"

class CSignature
{
public:
	DWORD dwFindPattern(DWORD dwAddress, DWORD dwLength, const char* szPattern);
	HMODULE GetModuleHandleSafe(const char* pszModuleName);
	DWORD GetClientSignature(char* chPattern);
	DWORD GetEngineSignature(char* chPattern);
	DWORD GetSignature(const char* pszModuleName, const char* szPattern);
};

extern CSignature gSignatures;