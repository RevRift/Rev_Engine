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

#ifdef REV_ENABLE_ASSERTS
	#define REV_ASSERTS(x, ...) if(!(x)) { REV_ERROR("Assertion-Failed: {0}", __VA_ARGS__}; __debugbreak(); ) } 
	#define REV_CORE_ASSERT(x, ...) if(!(x)) { REV_CORE_ERROR("Assertion-Failed: {0}", __VA_ARGS__}; __debugbreak(); ) } 
#else
	#define REV_ASSERT(x, ...)
	#define REV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)