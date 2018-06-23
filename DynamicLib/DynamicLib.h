#pragma once

#ifdef DYNAMICLLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif

// This class is exported from the Dynamic
class DYNAMICLIB_API CDynamicLib {
public:
	CDynamicLib(void);
	// TODO: add your methods here.
};

extern DYNAMICLIB_API int nDynamicLib;

DYNAMICLIB_API int fnDynamicLib(void);

extern "C" DYNAMICLIB_API int multiply(int a, int b);