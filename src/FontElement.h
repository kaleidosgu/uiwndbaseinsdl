#pragma once
#include "SDL_ttf.h"
class CFontElement
{
public:
	CFontElement(void);
	CFontElement( const std::string& strFont, int nFontSize, TTF_Font* pTtf );
	virtual ~CFontElement(void);
	std::string GetFont() const;
	TTF_Font* GetFontPoint() const;
private:
	std::string m_strFont;
	int m_nFontSize;
	TTF_Font* m_pTtf;
};
