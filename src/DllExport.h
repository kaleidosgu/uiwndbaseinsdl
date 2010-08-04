#ifndef _WND_DLL_EXPORT_H_
#define _WND_DLL_EXPORT_H_
	#ifdef _DEBUG
		#ifdef _Graphic_Lib
			#define WND_EXPORT __declspec(dllexport) 
		#else
			#define WND_EXPORT __declspec(dllimport) 
		#endif
	#endif
#endif