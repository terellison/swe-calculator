#include "../SWE_App/CalculatorProcessor.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{

	public:

		TEST_CLASS_CLEANUP(Cleanup)
		{
			CalculatorProcessor::ResetInstance();
		}

		TEST_METHOD(Simple_Addition_Test)
		{
			auto expression = "1+1";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(2.0f, result);
		}

		TEST_METHOD(Simple_Subtraction_Test)
		{
			auto expression = "1-1";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(0.0f, result);
		}
		
		TEST_METHOD(Simple_Multiplication_Test)
		{
			auto expression = "5*5";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(25.0f, result);
		}

		TEST_METHOD(Simple_Division_Test)
		{
			auto expression = "10/2";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(5.0f, result);
		}

		TEST_METHOD(Simple_Modulo_Test)
		{
			auto expression = "10%2";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(0.0f, result);
		}

		TEST_METHOD(Order_Of_Operations_Test_1)
		{
			auto expression = "(10/2)*5-4";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(21.0f, result);
		}

		TEST_METHOD(Order_Of_Operations_Test_2)
		{
			auto expression = "(9*9+7)/11+1";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(9.0f, result);
		}

		TEST_METHOD(Order_Of_Operations_Test_3)
		{
			auto expression = "(2*2*2*2*2*2)+16";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(80.0f, result);
		}

		TEST_METHOD(Expression_With_Large_Numbers)
		{
			auto expression = "((10000*9)/45000)*2";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(4.0f, result);
		}

		TEST_METHOD(Calculate_Pi)
		{
			auto expression = "22/7";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(3.142857f, result);
		}

		TEST_METHOD(Calculate_Four_Squared)
		{
			auto expression = "4^2";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(16.0f, result);
		}

		TEST_METHOD(Calculate_Twelve_Squared)
		{
			auto expression = "(6*2)^2";

			auto result = CalculatorProcessor::GetInstance()->ParseExpression(expression);

			Assert::AreEqual(144.0f, result);
		}
	};
}