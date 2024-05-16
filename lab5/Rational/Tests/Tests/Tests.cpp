#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"
#include "../../CRational.h"
#include <iostream>

SCENARIO("check initialization")
{
	{
		CRational number;
		REQUIRE(number.ToDouble() == 0);
	}
	{
		CRational number(7);
		REQUIRE(number.ToDouble() == 7);
	}
	{
		CRational number(8, 4);
		REQUIRE(number.ToDouble() == 2);
	}
	{
		CRational number(1, 2);
		REQUIRE(number.ToDouble() == 0.5);
	}
	{
		CRational number(4, 8);
		REQUIRE(number.GetNumerator() == 1);
		REQUIRE(number.GetDenominator() == 2);
	}
	/*{
		CRational number(1, 0);
	}*/
};

SCENARIO("check ChangeSign")
{
	CRational number(1, 2);
	number.ChangeSign();
	REQUIRE(number.ToDouble() == -0.5);
	number.ChangeSign();
	REQUIRE(number.ToDouble() == 0.5);
}

SCENARIO("check bin sum")
{
	CRational firstNum(1, 2), secondNum(1, 3);
	{
		CRational sum = firstNum + secondNum;
		double num(5.0 / 6.0);
		REQUIRE(sum.ToDouble() == num);
	}
	{
		CRational sum = firstNum + 2;
		double num(5.0 / 2.0);
		REQUIRE(sum.ToDouble() == num);
	}
	{
		CRational sum = 3 + secondNum;
		double num(10.0 / 3.0);
		REQUIRE(sum.ToDouble() == num);
	}
}

SCENARIO("check bin difference")
{
	CRational firstNum(1, 2), secondNum(1, 3);
	{
		CRational diff = firstNum - secondNum;
		double num(1.0 / 6.0);
		REQUIRE(diff.ToDouble() == num);
	}
	{
		CRational diff = firstNum - 2;
		double num(-3.0 / 2.0);
		REQUIRE(diff.ToDouble() == num);
	}
	{
		CRational diff = 3 - secondNum;
		double num(8.0 / 3.0);
		REQUIRE(diff.ToDouble() == num);
	}
}

SCENARIO("check += and -= operators")
{
	CRational firstNum(1, 2), secondNum(1, 2), thirdNum(1, 3), fourthNum(2, 4), fifthNum(4), sixthNum(8, 2);
	firstNum += secondNum;
	REQUIRE(firstNum.ToDouble() == 1.0);
	firstNum -= secondNum;
	REQUIRE(firstNum.ToDouble() == 1.0 / 2.0);
	thirdNum += 1;
	REQUIRE(thirdNum.ToDouble() == 4.0 / 3.0);
	thirdNum -= 1;
	REQUIRE(thirdNum.ToDouble() == 1.0 / 3.0);
	thirdNum += -1;
	REQUIRE(thirdNum.ToDouble() == -2.0 / 3.0);
	secondNum -= -1;
	REQUIRE(secondNum.ToDouble() == 3.0 / 2.0);
}

SCENARIO("check * operator")
{
	CRational firstNum(1, 2), secondNum(1, 3);
	{
		CRational res = firstNum * secondNum;
		double num(1.0 / 6.0);
		REQUIRE(res.ToDouble() == num);
	}
	{
		CRational res = firstNum * 2;
		double num(2.0 / 2.0);
		REQUIRE(res.ToDouble() == num);
	}
	{
		CRational res = 3 * secondNum;
		double num(3.0 / 3.0);
		REQUIRE(res.ToDouble() == num);
	}
}

SCENARIO("check / operator")
{
	CRational firstNum(1, 2), secondNum(1, 2), thirdNum(1, 3), fourthNum(2, 4), fifthNum(4), sixthNum(8, 2);
	{
		CRational res = firstNum / secondNum;
		REQUIRE(res.ToDouble() == 1.0);
	}
	//{
	//	CRational res = firstNum / 0;         //поправить тест через REQ(exception)
	//}
	{
		CRational res = firstNum / 3;
		REQUIRE(res.ToDouble() == 1.0 / 6.0);
	}
	{
		CRational res = 3 / secondNum;
		REQUIRE(res.ToDouble() == 6.0);
	}
	{
		CRational res = 0 / secondNum;
		REQUIRE(res.ToDouble() == 0.0);
	}
}

SCENARIO("check *= and /= operators")
{
	CRational firstNum(1, 2), secondNum(1, 2), thirdNum(1, 3), fourthNum(2, 4), fifthNum(4), sixthNum(8, 2);
	{
		CRational firstNum(1, 2), secondNum(1, 2);
		firstNum *= secondNum;
		REQUIRE(firstNum.ToDouble() == 1.0 / 4.0);
	}
	{
		CRational thirdNum(1, 3), fourthNum(2, 4);
		thirdNum /= fourthNum;
		REQUIRE(thirdNum.ToDouble() == 2.0 / 3.0);
	}
	{
		CRational thirdNum(1, 3);
		thirdNum *= 2;
		REQUIRE(thirdNum.ToDouble() == 2.0 / 3.0);
	}
	{
		CRational thirdNum(1, 3);
		thirdNum /= 4;
		REQUIRE(thirdNum.ToDouble() == 1.0 / 12.0);
	}
	{
		CRational thirdNum(1, 3);
		thirdNum *= 0;
		REQUIRE(thirdNum.ToDouble() == 0.0);
	}
	//{
	//	CRational thirdNum(1, 3);         //выбросит исключение
	//	thirdNum /= 0;
	//}
	//{
	//	CRational thirdNum(1, 3), zeroNum(0, 1);         //выбросит исключение
	//	thirdNum /= zeroNum;
	//}
}

SCENARIO("check == and != operators")
{
	CRational firstNum(1, 2), secondNum(1, 2), thirdNum(1, 3), fourthNum(2, 4), fifthNum(4), sixthNum(8, 2);
	{
		bool res = firstNum == secondNum;
		REQUIRE(res);
		res = firstNum == thirdNum;
		REQUIRE(!res);
		res = firstNum == fourthNum;
		REQUIRE(res);
		res = fifthNum == sixthNum;
		REQUIRE(res);
	}
	{
		bool res = firstNum != secondNum;
		REQUIRE(!res);
		res = firstNum != thirdNum;
		REQUIRE(res);
		res = firstNum != fourthNum;
		REQUIRE(!res);
		res = fifthNum != sixthNum;
		REQUIRE(!res);
	}
}

SCENARIO("check > and < operators")
{
	CRational firstNum(1, 2), secondNum(1, 2), thirdNum(1, 3), fourthNum(2, 4), fifthNum(4), sixthNum(8, 2);
	{
		bool res = firstNum > secondNum;
		REQUIRE(!res);
		res = firstNum > thirdNum;
		REQUIRE(res);
		res = firstNum > fourthNum;
		REQUIRE(!res);
		res = fifthNum > sixthNum;
		REQUIRE(!res);
		res = firstNum > 1;
		REQUIRE(!res);
		res = 1 > firstNum;
		REQUIRE(res);
	}
	{
		bool res = firstNum < secondNum;
		REQUIRE(!res);
		res = firstNum < thirdNum;
		REQUIRE(!res);
		res = firstNum < fourthNum;
		REQUIRE(!res);
		res = fifthNum < sixthNum;
		REQUIRE(!res);
		res = firstNum < 1;
		REQUIRE(res);
		res = 1 < firstNum;
		REQUIRE(!res);
	}
}

SCENARIO("check >= and <= operators")
{
	CRational firstNum(1, 2), secondNum(1, 2), thirdNum(1, 3), fourthNum(2, 4), fifthNum(4), sixthNum(8, 2);
	{
		bool res = firstNum >= secondNum;
		REQUIRE(res);
		res = firstNum >= thirdNum;
		REQUIRE(res);
		res = firstNum >= fourthNum;
		REQUIRE(res);
		res = fifthNum >= sixthNum;
		REQUIRE(res);
		res = firstNum >= 1;
		REQUIRE(!res);
		res = 1 >= firstNum;
		REQUIRE(res);
	}
	{
		bool res = firstNum <= secondNum;
		REQUIRE(res);
		res = firstNum <= thirdNum;
		REQUIRE(!res);
		res = firstNum <= fourthNum;
		REQUIRE(res);
		res = fifthNum <= sixthNum;
		REQUIRE(res);
		res = firstNum <= 1;
		REQUIRE(res);
		res = 1 <= firstNum;
		REQUIRE(res);
	}
}

SCENARIO("check >> operator")
{
	CRational rational;
	std::istringstream inputNum("1 / 2");
	inputNum >> rational;
	REQUIRE(rational.GetNumerator() == 1.0);
	REQUIRE(rational.GetDenominator() == 2.0);
}
