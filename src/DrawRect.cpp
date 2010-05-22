#include "StdAfx.h"
#include "DrawRect.h"
#include "GlobalSurface.h"

CDrawRect::CDrawRect(void)
{
	m_crR = 0;
	m_crG = 0;
	m_crB = 0;
}

CDrawRect::~CDrawRect(void)
{
}

void CDrawRect::OnDraw()
{
	if( IsVisible() )
	{
		SDL_FillRect( g_pScreen, &m_rect, SDL_MapRGB( g_pScreen->format, m_crR, m_crG, m_crB ) );
	}
	CDraw::OnDraw();
}
void CDrawRect::SetColor( const Uint8 r, const Uint8 g, const Uint8 b )
{
	m_crR = r;
	m_crG = g;
	m_crB = b;
}