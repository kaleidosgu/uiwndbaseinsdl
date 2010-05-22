#pragma once
#include "SDL_video.h"
#include "SDL_stdinc.h"
class CDraw
{
public:
	CDraw(void);
	virtual ~CDraw(void);
	virtual void Create( Sint16 x, Sint16 y, Sint16 w, Sint16 h );
	virtual void OnDraw();
	virtual void SetRect( const SDL_Rect& rect );
	virtual void SetRectAttr( const Sint16& x, const Sint16& y, const Uint16& w, const Uint16& h );
	virtual void SetPos( Sint16 x, Sint16 y );
	SDL_Rect GetRect() const;
	bool IsVisible() const;
private:
	bool m_bShow;
protected:
	SDL_Rect m_rect;
};
