#include "Paint.h"

void Paint(IDirect3DDevice9* pDevice)
{
	POINT cur;
	if (GetCursorPos(&cur) && ScreenToClient(GetForegroundWindow(), &cur) && cur.x && cur.y)
		gDraw->OutlineRect(cur.x, cur.y, 20, 20, Color(16, 64, 255));

	RECT text = gDraw->Text(10, 100, "Congratulations, you won", Color(255, 128, 32));
	gDraw->Line(text.left, text.bottom + 5, text.right, text.bottom + 5, Color(255, 64, 16), 3);
}