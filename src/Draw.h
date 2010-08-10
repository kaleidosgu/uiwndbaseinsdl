#pragma once
#include "SDL_video.h"
#include "SDL_stdinc.h"
#include "DllExport.h"
#include <list>
class WND_EXPORT CDraw
{
public:
	CDraw(void);
	virtual ~CDraw(void);
	virtual void Create( Sint16 x, Sint16 y, Sint16 w, Sint16 h );
	virtual void OnDraw();
	virtual void OnUpdate( const unsigned long& restTime );
	virtual void SetRect( const SDL_Rect& rect );
	virtual void SetRectAttr( const Sint16& x, const Sint16& y, const Uint16& w, const Uint16& h );
	virtual void SetPos( Sint16 x, Sint16 y );
	SDL_Rect GetRect() const;
	bool IsVisible() const;
	void SetVisible( bool bShow );
private:
	std::list < CDraw* > m_lstChild;
protected:
	bool m_bShow;
	SDL_Rect m_rect;
};
