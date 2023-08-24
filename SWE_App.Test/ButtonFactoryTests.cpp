#include "../SWE_App/ButtonFactory.h"
#include "../SWE_App/ButtonIDDefines.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
		wxFrame* parent = new wxFrame();
	public:
		TEST_METHOD(CreateAdd_ShouldReturn_Add_Button)
		{
			wxButton* button = ButtonFactory::CreateAddButton(parent);
			auto result = button->GetId();
			Assert::AreEqual((wxWindowID)'+', result);
		}

		TEST_METHOD(CreateMinus_ShouldReturn_Minus_Button)
		{
			wxButton* button = ButtonFactory::CreateMinusButton(parent);
			auto result = button->GetId();
			Assert::AreEqual((wxWindowID)'-', result);
		}

		TEST_METHOD(CreateMult_ShouldReturn_Mult_Button)
		{
			wxButton* button = ButtonFactory::CreateMultButton(parent);
			auto result = button->GetId();
			Assert::AreEqual((wxWindowID)'*', result);
		}

		TEST_METHOD(CreateDivide_ShouldReturn_Divide_Button)
		{
			wxButton* button = ButtonFactory::CreateDivideButton(parent);
			auto result = button->GetId();
			Assert::AreEqual((wxWindowID)'/', result);
		}

		TEST_METHOD(CreateModulo_ShouldReturn_Modulo_Button)
		{
			wxButton* button = ButtonFactory::CreateModuloButton(parent);
			auto result = button->GetId();
			Assert::AreEqual((wxWindowID)'%', result);
		}

		TEST_METHOD(CreateSin_ShouldReturn_Sin_Button)
		{
			wxButton* button = ButtonFactory::CreateSinButton(parent, SIN_BUTTON_ID);
			auto result = button->GetId();
			Assert::AreEqual(SIN_BUTTON_ID, result);
		}

		TEST_METHOD(CreateCosine_ShouldReturn_Cosine_Button)
		{
			wxButton* button = ButtonFactory::CreateCosineButton(parent, COSINE_BUTTON_ID);
			auto result = button->GetId();
			Assert::AreEqual(COSINE_BUTTON_ID, result);
		}

		TEST_METHOD(CreateTangent_ShouldReturn_Tangent_Button)
		{
			wxButton* button = ButtonFactory::CreateTangentButton(parent, TANGENT_BUTTON_ID);
			auto result = button->GetId();
			Assert::AreEqual(TANGENT_BUTTON_ID, result);
		}

		TEST_METHOD(CreateDelete_ShouldReturn_Delete_Button)
		{
			wxButton* button = ButtonFactory::CreateDeleteButton(parent, DELETE_BUTTON_ID);
			auto result = button->GetId();
			Assert::AreEqual(DELETE_BUTTON_ID, result);
		}

		TEST_METHOD(CreateClear_ShouldReturn_Clear_Button)
		{
			wxButton* button = ButtonFactory::CreateClearButton(parent, CLEAR_BUTTON_ID);
			auto result = button->GetId();
			Assert::AreEqual(CLEAR_BUTTON_ID, result);
		}
	};
}
