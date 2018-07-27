#pragma once
#include "Base.h"
#include <d3d9.h>

extern HRESULT(STDMETHODCALLTYPE *original_present) (IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
extern HRESULT(STDMETHODCALLTYPE *original_reset) (IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);

HRESULT STDMETHODCALLTYPE present(IDirect3DDevice9* thisptr, const RECT* src, const RECT* dest, HWND wnd_override, const RGNDATA* dirty_region);
HRESULT STDMETHODCALLTYPE reset(IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* params);