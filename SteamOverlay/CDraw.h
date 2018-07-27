#pragma once
#include "Color.h"

class CDrawManager
{
public:
	void Rect(long x, long y, long w, long h, Color color);
	void OutlineRect(long x, long y, long w, long h, Color color);
	void Line(long x1, long y1, long x2, long y2, Color color, float width = 1);
	RECT Text(long x, long y, const char* szText, Color color, ID3DXFont* Font = nullptr);
	RECT TextSize(const char* szText, ID3DXFont* Font = nullptr);

	ID3DXFont* Tahoma = nullptr;

	inline bool UpdateDevice(IDirect3DDevice9* DrawingDevice)
	{
		if (!DrawingDevice)
			return gBase.Fatal("CDrawManager recieved an invalid drawing device.");
		return pDevice = DrawingDevice;
	}
	CDrawManager(IDirect3DDevice9* DrawingDevice)
	{
		if (!DrawingDevice)
		{
			gBase.Fatal("CDrawManager recieved an invalid drawing device.");
			return;
		}
		pDevice = DrawingDevice;
		CreateFonts();
	}
	~CDrawManager()
	{
		if (Tahoma)
		{
			Tahoma->Release();
			Tahoma = nullptr;
		}
	}

private:
	IDirect3DDevice9 * pDevice = nullptr;
	void CreateFonts();
};