#include "Paint.h"

void Paint(IDirect3DDevice9* pDevice)
{
	POINT cur;
	if (GetCursorPos(&cur) && ScreenToClient(GetForegroundWindow(), &cur) && cur.x && cur.y)
		gDraw->Rect(cur.x, cur.y, 20, 20, Color(16, 64, 255));

	gDraw->Text(10, 100, "Congratulations, you won", Color(255, 128, 32));
}