#pragma once
#include "SDL_video.h"
#include "SDL_stdinc.h"
#include "Draw.h"
#include "DllExport.h"

class WND_EXPORT CDrawRect : public CDraw
{
public:
	CDrawRect(void);
	virtual ~CDrawRect(void);
	virtual void OnDraw();
	void SetColor( const Uint8 r, const Uint8 g, const Uint8 b );
	void GetColor( Uint8& r, Uint8& g, Uint8& b );
private:
	Uint8 m_crR;
	Uint8 m_crG;
	Uint8 m_crB;
};
