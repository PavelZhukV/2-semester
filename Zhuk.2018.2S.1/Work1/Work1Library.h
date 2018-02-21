#pragma once

#ifdef WORK1_EXPORTS
#define WORK1LIBRARY_API __declspec(dllexport)
#else
#define WORK1LIBRARY_API __declspec(dllimport)
#endif // WORK1LIBRARY_EXPORTS



namespace Work1
{
	WORK1LIBRARY_API void hexInclusionSort(int [],int );

	WORK1LIBRARY_API void deleteElement(int array[], int & n,int num);

	WORK1LIBRARY_API bool isBadNumber(int x,int badsymbol);

	WORK1LIBRARY_API int firstHexSymbol(int );

	WORK1LIBRARY_API void task13(int array[], int & n, char a, int narray[], int & k);

	WORK1LIBRARY_API int badSymbol(char symbol);

	WORK1LIBRARY_API void deleteEqualElements(int array[], int & n);
}