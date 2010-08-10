#include "StdAfx.h"
#include "Draw.h"

CDraw::CDraw(void)
{
	m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = 0;
	m_rect.h = 0;
	m_bShow = true;
}

CDraw::~CDraw(void)
{
}
void CDraw::OnDraw()
{
	if( m_bShow )
	{
		for( std::list < CDraw* >::iterator it = m_lstChild.begin(); it != m_lstChild.end(); ++it )
		{
			CDraw* pDraw = (*it);
			pDraw->OnDraw();
		}
	}
}
void CDraw::SetRect( const SDL_Rect& rect )
{
	m_rect = rect;
}
void CDraw::SetRectAttr( const Sint16& x, const Sint16& y, const Uint16& w, const Uint16& h )
{
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}
void CDraw::SetPos( Sint16 x, Sint16 y )
{
	m_rect.x = x;
	m_rect.y = y;
}

bool CDraw::IsVisible() const
{
	return m_bShow;
}
SDL_Rect CDraw::GetRect() const
{
	return m_rect;
}
void CDraw::Create( Sint16 x, Sint16 y, Sint16 w, Sint16 h )
{
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}
void CDraw::OnUpdate()
{
	if( m_bShow )
	{
		for( std::list < CDraw* >::iterator it = m_lstChild.begin(); it != m_lstChild.end(); ++it )
		{
			CDraw* pDraw = (*it);
			pDraw->OnUpdate();
		}
	}
}