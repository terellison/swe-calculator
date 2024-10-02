#include "Calculator.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

wxBEGIN_EVENT_TABLE(Calculator, wxFrame)
	EVT_BUTTON((unsigned int)'=', Calculator::OnEqualButtonClicked)
	EVT_BUTTON(wxID_ANY, Calculator::OnButtonClicked)
wxEND_EVENT_TABLE()

void Calculator::SetupRow1()
{
	Buttons.push_back(ButtonFactory::CreateExponentButton(this));
	Buttons.push_back(ButtonFactory::CreateOpenParenthesesButton(this));
	Buttons.push_back(ButtonFactory::CreateClosingParenthesesButton(this));
	Buttons.push_back(ButtonFactory::CreateClearButton(this, CLEAR_BUTTON_ID));
	
	row1->AddSpacer(WINDOW_WIDTH - (ButtonFactory::ButtonSize->GetWidth() * 4));
	row1->Add(GetButtonInstanceByID('^'), 2, wxEXPAND, 10);
	row1->Add(GetButtonInstanceByID('('), 2, wxEXPAND, 10);
	row1->Add(GetButtonInstanceByID(')'), 2, wxEXPAND, 10);
	row1->Add(GetButtonInstanceByID(CLEAR_BUTTON_ID), 2, wxEXPAND, 10);

	topSizer->Add(row1, 1);
}
void Calculator::SetupRow2()
{
	Buttons.push_back(ButtonFactory::CreateSevenButton(this));
	Buttons.push_back(ButtonFactory::CreateEightButton(this));
	Buttons.push_back(ButtonFactory::CreateNineButton(this));
	Buttons.push_back(ButtonFactory::CreateSinButton(this, SIN_BUTTON_ID));
	Buttons.push_back(ButtonFactory::CreateDeleteButton(this, DELETE_BUTTON_ID));

	row2->Add(GetButtonInstanceByID(7), 2, wxEXPAND, 10);
	row2->Add(GetButtonInstanceByID(8), 2, wxEXPAND, 10);
	row2->Add(GetButtonInstanceByID(9), 2, wxEXPAND, 10);
	row2->Add(GetButtonInstanceByID(SIN_BUTTON_ID), 2, wxEXPAND, 10);
	row2->Add(GetButtonInstanceByID(DELETE_BUTTON_ID), 2, wxEXPAND, 10);

	topSizer->Add(row2, 1);
}
void Calculator::SetupRow3()
{	

	Buttons.push_back(ButtonFactory::CreateSixButton(this));
	Buttons.push_back(ButtonFactory::CreateFiveButton(this));
	Buttons.push_back(ButtonFactory::CreateFourButton(this));
	Buttons.push_back(ButtonFactory::CreateCosineButton(this, COSINE_BUTTON_ID));
	Buttons.push_back(ButtonFactory::CreateAddButton(this));
	
	row3->Add(GetButtonInstanceByID(6), 2, wxEXPAND, 10);
	row3->Add(GetButtonInstanceByID(5), 2, wxEXPAND, 10);
	row3->Add(GetButtonInstanceByID(4), 2, wxEXPAND, 10);
	row3->Add(GetButtonInstanceByID(COSINE_BUTTON_ID), 2, wxEXPAND, 10);
	row3->Add(GetButtonInstanceByID('+'), 2, wxEXPAND, 10);

	topSizer->Add(row3, 1);
}
void Calculator::SetupRow4()
{
	Buttons.push_back(ButtonFactory::CreateThreeButton(this));
	Buttons.push_back(ButtonFactory::CreateTwoButton(this));
	Buttons.push_back(ButtonFactory::CreateOneButton(this));
	Buttons.push_back(ButtonFactory::CreateTangentButton(this, TANGENT_BUTTON_ID));
	Buttons.push_back(ButtonFactory::CreateMinusButton(this));

	row4->Add(GetButtonInstanceByID(3), 2, wxEXPAND, 10);
	row4->Add(GetButtonInstanceByID(2), 2, wxEXPAND, 10);
	row4->Add(GetButtonInstanceByID(1), 2, wxEXPAND, 10);
	row4->Add(GetButtonInstanceByID(TANGENT_BUTTON_ID), 2, wxEXPAND, 10);
	row4->Add(GetButtonInstanceByID('-'), 2, wxEXPAND, 10);

	topSizer->Add(row4, 1);
}
void Calculator::SetupRow5()
{
	Buttons.push_back(ButtonFactory::CreateModuloButton(this));
	Buttons.push_back(ButtonFactory::CreateZeroButton(this));
	Buttons.push_back(ButtonFactory::CreateMultButton(this));
	Buttons.push_back(ButtonFactory::CreateDivideButton(this));
	Buttons.push_back(ButtonFactory::CreateEqualButton(this));

	row5->Add(GetButtonInstanceByID('%'), 2, wxEXPAND, 10);
	row5->Add(GetButtonInstanceByID(0), 2, wxEXPAND, 10);
	row5->Add(GetButtonInstanceByID('*'), 2, wxEXPAND, 10);
	row5->Add(GetButtonInstanceByID('/'), 2, wxEXPAND, 10);
	row5->Add(GetButtonInstanceByID('='), 2, wxEXPAND, 10);

	topSizer->Add(row5, 1);
}

Calculator::Calculator() : wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxSize(WINDOW_WIDTH, WINDOW_HEIGHT))
{
	ButtonFactory::ButtonSize->SetHeight(NUMBER_BOX_HEIGHT);
	ButtonFactory::ButtonSize->SetWidth(WINDOW_WIDTH / 5);

	wxFont numberBoxStyle(wxFontInfo(FONT_SIZE));

	NumberBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 0), wxSize(WINDOW_WIDTH, NUMBER_BOX_HEIGHT), wxTE_RIGHT);
	NumberBox->SetFont(numberBoxStyle);
	NumberBox->Disable();
	topSizer->Add(NumberBox, 1, wxEXPAND, 10);
	SetupRow1();
	SetupRow2();
	SetupRow3();
	SetupRow4();
	SetupRow5();
	SetSizerAndFit(topSizer);
}

void Calculator::OnButtonClicked(wxCommandEvent& evt)
{
	unsigned int id = evt.GetId();

	if (id >= 0 && id <= 9)
	{
		NumberBox->AppendText(std::to_string(id));
		return;
	}

	switch (id)
	{
	case DELETE_BUTTON_ID:
	{
		auto currentText = NumberBox->GetValue();
		auto newText = currentText.substr(0, currentText.length() - 1);
		NumberBox->Clear();
		NumberBox->WriteText(newText);
		break;
	}
	case CLEAR_BUTTON_ID:
		NumberBox->Clear();
		break;
	case SIN_BUTTON_ID:
	case COSINE_BUTTON_ID:
	case TANGENT_BUTTON_ID:
	{
		auto currentText = (std::string)NumberBox->GetValue();
		NumberBox->Clear();
		try
		{
			auto num = CalculatorProcessor::GetInstance()->EvaluateTrigFunction(id, currentText);
			NumberBox->WriteText(std::to_string(num));
		}
		catch (...)
		{
			NumberBox->WriteText("Invalid syntax");
		}
		break;
	}
	default:
		NumberBox->AppendText((char)id);
		break;
	}

	CalculatorProcessor::ResetInstance();
}

void Calculator::OnEqualButtonClicked(wxCommandEvent& evt)
{
	auto text = NumberBox->GetValue();

	auto processor = CalculatorProcessor::GetInstance();

	NumberBox->Clear();
	try
	{
		float result = processor->ParseExpression(text.ToStdString());
		NumberBox->WriteText(std::to_string(result));
	}
	catch (...)
	{
		NumberBox->WriteText("Invalid syntax");
	}

	CalculatorProcessor::ResetInstance();
}

wxButton* Calculator::GetButtonInstanceByID(wxWindowID id)
{
	return *(std::find_if(Buttons.begin(), Buttons.end(), [&id](const wxButton* button) { return button->GetId() == id; }));
}
