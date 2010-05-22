#include "StdAfx.h"
#include "FontElement.h"

CFontElement::CFontElement(void)
:m_pTtf( NULL), m_strFont(""),m_nFontSize(0)
{
}

CFontElement::~CFontElement(void)
{
}

CFontElement::CFontElement( const std::string& strFont, int nFontSize, TTF_Font* pTtf  )
:m_pTtf( NULL), m_strFont(strFont),m_nFontSize(nFontSize)
{
}

std::string CFontElement::GetFont() const
{
	return m_strFont;
}
TTF_Font* CFontElement::GetFontPoint() const
{
	return m_pTtf;
}