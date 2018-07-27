#pragma once
#include "Base.h"

class Color
{
public:
	byte r, g, b, a;

	Color(byte red, byte green, byte blue, byte alpha = 255)
	{
		r = red, g = green, b = blue, a = alpha;
	}
	Color(byte brightness, byte alpha = 255)
	{
		r = g = b = brightness, a = alpha;
	}

	void ToFloat(float flColor[3])
	{
		flColor[0] = float(r) / 255.f;
		flColor[1] = float(g) / 255.f;
		flColor[2] = float(b) / 255.f;
		flColor[3] = float(a) / 255.f;
	}

	DWORD ARGB()
	{
		return ((DWORD)(
			(((a) & 0xff) << 24) |
			(((r) & 0xff) << 16) |
			(((g) & 0xff) << 8) |
			((b) & 0xff)));
	}
};