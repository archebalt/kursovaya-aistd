#include "pch.h"
#include "CppUnitTest.h"
#include "../kursovaya_aistd/Functions.h"
#include "../kursovaya_aistd/Functions.cpp"
#include "../kursovaya_aistd/MyList.h"
#include "../kursovaya_aistd/MyList.cpp"
#include "../kursovaya_aistd/Element.h"
#include "../kursovaya_aistd/Element.cpp"
#include "../kursovaya_aistd/Stack.h"
#include "../kursovaya_aistd/Stack.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		string str;
		TEST_METHOD(calculate1)
		{
			str = "tg(pi/4)*3.5";
			MyList* elements = chek_and_separation(str);
			MyList* new_elements = from_infix_to_prefix(elements);
			MyList* again = reverse(new_elements);
			MyList* again1 = out_this_and_copy(again);
			double num = tan(M_PI/4)*3.5;
			double res = calculate_it(again1);
			Assert::AreEqual(res, num);
		}
		TEST_METHOD(calculate2)
		{
			str = "(ln(12*sin(3*pi/4))/2)^2";
			MyList* elements = chek_and_separation(str);
			MyList* new_elements = from_infix_to_prefix(elements);
			MyList* again = reverse(new_elements);
			MyList* again1 = out_this_and_copy(again);
			double num = pow((log(12*sin(3*M_PI/4))/2),2);
			double res = calculate_it(again1);
			Assert::AreEqual(res, num);
		}
		TEST_METHOD(check1)
		{
			correct = true;
			str = "2*2))";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check2)
		{
			correct = true;
			str = "2**2";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check3)
		{
			correct = true;
			str = "2)2";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check4)
		{
			correct = true;
			str = "2sin(2)";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check5)
		{
			correct = true;
			str = "2*sin2)";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check6)
		{
			correct = true;
			str = "2*san(pi)";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check7)
		{
			correct = true;
			str = "3+(*6+5)";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check8)
		{
			correct = true;
			str = "4tg(8)";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check9)
		{
			correct = true;
			str = "(5*6.8.9)+5";
			MyList* elements = chek_and_separation(str);
			Assert::IsFalse(correct);
		}
		TEST_METHOD(check10)
		{
			correct = true;
			str = "(588-5*(exp(6)))^3";
			MyList* elements = chek_and_separation(str);
			Assert::IsTrue(correct);
		}
		TEST_METHOD(check11)
		{
			correct = true;
			str = "ctg(13*45.2)/3";
			MyList* elements = chek_and_separation(str);
			Assert::IsTrue(correct);
		}
	};
}
