#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1_2/Account.h"
#include "../Lab1_2/Account.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Account a, b;
			bool res1, res2;
			res1 = a.SetNo(2);
			res2 = b.SetNo(3);
			Assert::IsTrue(res1);
			Assert::IsTrue(res2);
		}

	};
}