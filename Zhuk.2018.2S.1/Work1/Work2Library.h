#pragma once

#ifdef WORK2_EXPORTS
#define WORK2LIBRARY_API __declspec(dllexport)
#else
#define WORK2LIBRARY_API __declspec(dllimport)
#endif // WORK1LIBRARY_EXPORTS



namespace Work2
{
	WORK2LIBRARY_API void hexInclusionSort(int [],int );

	WORK2LIBRARY_API void deleteElement(int array[], int & n,int num);

	WORK2LIBRARY_API bool isBadNumber(int x,int badsymbol);

	WORK2LIBRARY_API int firstHexSymbol(int );

	WORK2LIBRARY_API void task13(int array[], int & n, char a, int narray[], int & k);

	WORK2LIBRARY_API int badSymbol(char symbol);

	WORK2LIBRARY_API void deleteEqualElements(int array[], int & n);

	WORK2LIBRARY_API void deleteInNewArray(int array[], int & n, char a, int narray[], int & k);
}