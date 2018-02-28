#include "stdafx.h"
#include "CppUnitTest.h"
#include "Work1Library.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int array[] = { 1,5,16,7,20,22,46,22,30 } ;
			int narray[256] ;
			int n = 9,k = 0;
			char a = 'E';
			int resarray[] = { 1,16,20,22,5,7 };
			int resnarray[] = { 30,46 };

			Work1::task13(array, n, a, narray, k);

			Assert::AreEqual(n, 6);
			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], resarray[i]);
			}
			Assert::AreEqual(k, 2);
			for (int i = 0; i < k; i++)
			{
				Assert::AreEqual(narray[i], resnarray[i]);
			}
		}
		TEST_METHOD(TestMethod2)
		{
			int array[] = { 1,5,16,7,20,22,22,30,46 };
			int resarray[] = { 1,16,20,22,22,30,46,5,7 };
			int n = 9;

			Work1::hexInclusionSort(array, n);


			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], resarray[i]);
			}

		}
		TEST_METHOD(TestMethod3)
		{
			int array[] = { 1,5,16,7,20,22,22,30,46 };
			int resarray[] = { 1,5,16,20,22,22,30,46 };
			int n = 9;
			int num = 3;

			Work1::deleteElement(array,n,num);


			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], resarray[i]);
			}

		}
		TEST_METHOD(TestMethod4)
		{
			int x = 9;
			int y = 30;

			Work1::isBadNumber(x,14);
			Work1::isBadNumber(y, 14);


			Assert::IsTrue(Work1::isBadNumber(y, 14));
			Assert::IsFalse(Work1::isBadNumber(x, 14));


		}
		TEST_METHOD(TestMethod5)
		{
			int x = 9;
			int y = 30;
			int z = 46;
			int resx = 9, resy = 1, resz = 2;


			Assert::AreEqual(Work1::firstHexSymbol(x),resx);
			Assert::AreEqual(Work1::firstHexSymbol(y), resy);
			Assert::AreEqual(Work1::firstHexSymbol(z), resz);


		}
		TEST_METHOD(TestMethod6)
		{
			char a = 'A';
			int reza = 10;
			char b = 'B';
			int rezb = 11;
			char f = 'F';
			int rezf = 15;


			Assert::AreEqual(Work1::badSymbol(a),reza);
			Assert::AreEqual(Work1::badSymbol(b), rezb);
			Assert::AreEqual(Work1::badSymbol(f), rezf);


		}
		TEST_METHOD(TestMethod7)
		{
			int array[] = { 1,2,2,4,5,5,6,6,7,7,7,8,8,8,8 };
			int resarray[] = { 1,2,4,5,6,7,8 };
			int n = 9;

			Work1::deleteEqualElements(array,n);


			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], resarray[i]);
			}

		}
		TEST_METHOD(TestMethod8)
		{
			int array[] = { 1,5,16,30,7,20,22,14,46 };
			int narray[256];
			int n = 9, k = 0;
			char a = 'E';
			int resarray[] = { 1,5,16,7,20,22 };
			int resnarray[] = { 30,14,46 };

			Work1::deleteInNewArray(array, n, a, narray, k);

			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(array[i], resarray[i]);
			}
			for (int i = 0; i < k; i++)
			{
				Assert::AreEqual(narray[i], resnarray[i]);
			}
		}
	};
}