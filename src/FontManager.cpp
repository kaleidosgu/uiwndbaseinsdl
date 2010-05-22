#include "stdafx.h"
#include "FontManager.h"
#include "FontElement.h"
CFontManager*   CFontManager::m_pManager   =   0;   
CFontManager::CFontManager(void)
{
}

CFontManager::~CFontManager(void)
{
}

void CFontManager::Destroy()
{
	for( std::map < int, std::vector < CFontElement* > >::iterator it = m_mapElement.begin(); it != m_mapElement.end(); ++it )
	{
		std::vector < CFontElement* >& vec = it->second;
		for( std::vector < CFontElement* >::iterator itV = vec.begin(); itV != vec.end(); ++itV )
		{
			CFontElement* pItem = (*itV);
			TTF_CloseFont( pItem->GetFontPoint() );
			delete pItem;
		}
	}
}
CFontManager* CFontManager::GetInstance()
{
	if( m_pManager == NULL )
	{
		m_pManager = new CFontManager;
	}
	return m_pManager;
}

TTF_Font* CFontManager::_CreateFont( const std::string& strFont, int nFontSize )
{
	CFontElement* pItem = NULL;
	TTF_Font* pFontPoint = TTF_OpenFont( strFont.c_str(), nFontSize );
	if( pFontPoint )
	{
		pItem = new CFontElement(strFont, nFontSize, pFontPoint);
		std::vector < CFontElement* > vec;
		vec.push_back( pItem );
		m_mapElement.insert( make_pair( nFontSize, vec ) );
	}
	return pFontPoint;
}

TTF_Font* CFontManager::GetFont( const std::string& strFont, int nFontSize )
{
	TTF_Font* pFontPoint = NULL;
	std::map < int, std::vector < CFontElement* > >::iterator it = m_mapElement.find( nFontSize );
	if( it == m_mapElement.end() )
	{
		pFontPoint = _CreateFont( strFont, nFontSize );
	}
	else
	{
		std::vector < CFontElement* >& vec = it->second;
		for( std::vector < CFontElement* >::iterator it = vec.begin(); it != vec.end(); ++it )
		{
			CFontElement* pItem = (*it);
			const std::string& str = pItem->GetFont();
			if( str.compare( strFont ) == 0 )
			{
				pFontPoint = pItem->GetFontPoint();
				//’“µΩ.
				break;
			}
		}
		//√ª’“µΩ
		pFontPoint = _CreateFont( strFont, nFontSize );

	}
	return pFontPoint;
}