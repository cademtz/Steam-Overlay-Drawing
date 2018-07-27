#include "OverlayHooks.h"
#include "CDraw.h"

HRESULT(STDMETHODCALLTYPE *original_present) (IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
HRESULT(STDMETHODCALLTYPE *original_reset) (IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);

#include "Paint.h"
HRESULT STDMETHODCALLTYPE present(IDirect3DDevice9* thisptr, const RECT* src, const RECT* dest, HWND wnd_override, const RGNDATA* dirty_region)
{
	if (!gDraw)
		gDraw = new CDrawManager(thisptr);
	gDraw->UpdateDevice(thisptr);

	Paint(thisptr);
	return original_present(thisptr, src, dest, wnd_override, dirty_region);
}

HRESULT STDMETHODCALLTYPE reset(IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* params)
{
	return original_reset(thisptr, params);
}