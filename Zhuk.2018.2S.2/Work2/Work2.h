#pragma once

#ifdef WORK2_EXPORTS
#define WORK2LIBRARY_API __declspec(dllexport)
#else
#define WORK2LIBRARY_API __declspec(dllimport)
#endif 

namespace Work2
{
	WORK2LIBRARY_API void initZeroMatrix(double** , int );

	WORK2LIBRARY_API double** allocateMemoryForMatrix(int );

	WORK2LIBRARY_API double cosTaylor(int , double);

	WORK2LIBRARY_API double sinTaylor(int , double);

	WORK2LIBRARY_API void matrixTaylor(double** , int , double);

	WORK2LIBRARY_API void matrix(double**, int );
}