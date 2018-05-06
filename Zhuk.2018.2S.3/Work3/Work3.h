#pragma once

#ifdef WORK3_EXPORTS
#define WORK3LIBRARY_API __declspec(dllexport)
#else
#define WORK3LIBRARY_API __declspec(dllimport)
#endif 

namespace Work3
{
	WORK3LIBRARY_API int** allocateMemoryForMatrix(int n);
	WORK3LIBRARY_API void initRandMatrix(int** matrix, int n);
	WORK3LIBRARY_API int maxElement(int** matrix, int a, int b, int n);
	WORK3LIBRARY_API int** task8(int** matrix, int n);
	WORK3LIBRARY_API void swap(int& a, int& b);
}