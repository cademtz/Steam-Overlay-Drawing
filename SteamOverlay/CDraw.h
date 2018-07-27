#pragma once
#include "Color.h"

class CDrawManager
{
public:
	void Rect(int x, int y, int w, int h, Color color);
	void Text(int x, int y, const char* szText, Color color, ID3DXFont* font = nullptr);

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