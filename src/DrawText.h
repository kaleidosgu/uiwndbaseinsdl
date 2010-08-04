#pragma once
#include "Draw.h"
#include "SDL_ttf.h"
#include "DllExport.h"
class WND_EXPORT CDrawText :
	public CDraw
{
public:
	CDrawText(void);
	virtual ~CDrawText(void);
	virtual void OnDraw();
	virtual void Create( Sint16 x, Sint16 y, Sint16 w, Sint16 h );
	void SetFontAttr( const std::string& strFont, int nFontSize );
	void SetColor( const SDL_Color& cr );
	void SetText( const std::string& str );
	void SetText( const char* pText );
private:
	void _ResetAttr( const std::string& strFont, int nFontSize );
private:
	SDL_Surface* m_pSurface;
	TTF_Font* m_pFont;
	SDL_Color m_cr;
	std::string m_str;
	int m_nFontSize;
	std::string m_strFont;
};
