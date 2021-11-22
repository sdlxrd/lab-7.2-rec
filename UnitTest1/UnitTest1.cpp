#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\lab 7.2 rec\lab 7.2 rec\lab 7.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 2;
			int n = 2;
			int id = 0;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			a[0][0] = 0;
			a[0][1] = 3;
			a[1][0] = 2;
			a[1][1] = 6;
			int i;
			i = Min(a, k, n, 0, 0, id, id );
			Assert::AreEqual(i, 0);
		}
	};
}
