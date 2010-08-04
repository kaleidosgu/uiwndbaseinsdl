#pragma once
#include <map>
#include <vector>
#include "SDL_ttf.h"
#include "DllExport.h"
class CFontElement;
class WND_EXPORT CFontManager
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
