#include "CDraw.h"

#define SAFEDRAW()														\
if (!pDevice)															\
{																		\
	gBase.Fatal("CDrawManager recieved an invalid drawing device.");	\
	return;																\
}

void CDrawManager::CreateFonts()
{
	SAFEDRAW();
	HRESULT result = D3DXCreateFont(pDevice, 20, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, "Tahoma", &Tahoma);

	if (!SUCCEEDED(result))
		gBase.Fatal("Couldn't initialize fonts with the drawing device.");
}

void CDrawManager::Rect(int x, int y, int w, int h, Color color)
{
	SAFEDRAW();
	
	D3DRECT pos = { x, y, x + w, y + h };
	pDevice->Clear(1, &pos, D3DCLEAR_TARGET | D3DCLEAR_TARGET, color.ARGB(), 0, 0);
}

void CDrawManager::Text(int x, int y, const char* szText, Color color, ID3DXFont* font)
{
	SAFEDRAW();

	if (!font)
		font = Tahoma;

	RECT pos = { x, y, x, y };
	font->DrawTextA(NULL, szText, -1, &pos, DT_CALCRECT, color.ARGB());
	font->DrawTextA(NULL, szText, -1, &pos, DT_LEFT, color.ARGB());
}