#pragma once

#ifdef WORK4_EXPORTS
#define WORK4LIBRARY_API __declspec(dllexport)
#else
#define WORK4LIBRARY_API __declspec(dllimport)
#endif 

namespace Work4
{
	WORK4LIBRARY_API int ** allocateMemoryForMatrix(int n);
	WORK4LIBRARY_API void initRandMatrix(int ** matrix, int n);
	WORK4LIBRARY_API int ** task13(int ** matrix, int n);
	WORK4LIBRARY_API void initZeroMatrix(int ** matrix, int n);
}