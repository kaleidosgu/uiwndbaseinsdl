#include "StdAfx.h"
#include "DrawText.h"
#include "FontManager.h"
#include "GlobalSurface.h"
CDrawText::CDrawText(void)
:m_pSurface(NULL),m_pFont(NULL),m_str(""),m_nFontSize(0)
{
	m_cr.r = 0;
	m_cr.g = 0;
	m_cr.b = 0;
}

CDrawText::~CDrawText(void)
{
	SDL_FreeSurface( m_pSurface );
}
void CDrawText::Create( Sint16 x, Sint16 y, Sint16 w, Sint16 h )
{
	CDraw::Create(x,y,w,h);
}
void CDrawText::SetFontAttr( const std::string& strFont, int nFontSize )
{
	m_strFont = strFont;
	m_nFontSize = nFontSize;
	m_pFont = CFontManager::GetInstance()->GetFont( strFont, nFontSize );
	_ResetAttr( strFont, nFontSize );
}
void CDrawText::_ResetAttr( const std::string& strFont, int nFontSize )
{
	if( m_pSurface )
	{
		SDL_FreeSurface( m_pSurface );
		m_pSurface = NULL;
	}
	m_pSurface = TTF_RenderText_Solid( m_pFont, m_str.c_str(), m_cr );
}

void CDrawText::OnDraw()
{
	if( IsVisible() )
	{
		SDL_BlitSurface( m_pSurface, NULL, g_pScreen, &m_rect );
	}
	CDraw::OnDraw();
}

void CDrawText::SetColor( const SDL_Color& cr )
{
	m_cr = cr;
}
void CDrawText::SetText( const std::string& str )
{
	m_str = str;
	_ResetAttr( m_strFont, m_nFontSize );
}
void CDrawText::SetText( const char* pText )
{
	if( pText )
	{
		m_str = pText;
	}
	_ResetAttr( m_strFont, m_nFontSize );
}