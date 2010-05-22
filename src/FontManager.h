#pragma once
#include <map>
#include <vector>
class CFontElement;
#include "SDL_ttf.h"
class CFontManager
{
public:
	virtual ~CFontManager(void);
	static CFontManager* GetInstance();
	TTF_Font* GetFont( const std::string& strFont, int nFontSize );
	void Destroy();
private:
	CFontManager(void);
	TTF_Font* _CreateFont( const std::string& strFont, int nFontSize );
public:
	static CFontManager* m_pManager;
private:
	std::map < int, std::vector < CFontElement* > > m_mapElement;
};
