#pragma once

#ifdef REV_PLATFORM_WINDOWS
	#ifdef REV_BUILD_DLL
		#define REV_API __declspec(dllexport)
	#else 
		#define REV_API __declspec(dllimport)
	#endif
#else
	#error Rev only supports Windows
#endif


#define BIT(x) (1 << x)