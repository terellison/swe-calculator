#include "wx\wx.h"
#pragma once
class ButtonFactory
{
private:
	
	static wxButton* CreateButton(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& label = wxEmptyString, const wxPoint position = wxDefaultPosition);
	/// <summary>
	/// Creates a new button. Uses the ASCII value of the label as the id of the button
	/// </summary>
	/// <param name="parent">Pointer to the parent window</param>
	/// <param name="label">Symbol to be displayed on the button</param>
	/// <returns>Pointer to the buton that was created</returns>
	static wxButton* CreateButton(wxWindow* parent, const char& label);

	/// <summary>
	/// Creates a new button. Used for numerical buttons
	/// </summary>
	/// <param name="parent">Pointer to the parent window of the button</param>
	/// <param name="label">Number to be displayed on the button</param>
	/// <returns></returns>
	static wxButton* CreateButton(wxWindow* parent, unsigned int label);
public:
	static wxSize* ButtonSize;
	static wxButton* CreateAddButton(wxWindow* parent);
	static wxButton* CreateMinusButton(wxWindow* parent);
	static wxButton* CreateMultButton(wxWindow* parent);
	static wxButton* CreateDivideButton(wxWindow* parent);
	
	static wxButton* CreateEqualButton(wxWindow* parent);
	static wxButton* CreateClearButton(wxWindow* parent, wxWindowID id);
	static wxButton* CreateDeleteButton(wxWindow* parent, wxWindowID id);
	static wxButton* CreateModuloButton(wxWindow* parent);

	static wxButton* CreateSinButton(wxWindow* parent, wxWindowID id);
	static wxButton* CreateCosineButton(wxWindow* parent, wxWindowID id);
	static wxButton* CreateTangentButton(wxWindow* parent, wxWindowID id);

	static wxButton* CreateZeroButton(wxWindow* parent);
	static wxButton* CreateOneButton(wxWindow* parent);
	static wxButton* CreateTwoButton(wxWindow* parent);
	static wxButton* CreateThreeButton(wxWindow* parent);
	static wxButton* CreateFourButton(wxWindow* parent);
	static wxButton* CreateFiveButton(wxWindow* parent);
	static wxButton* CreateSixButton(wxWindow* parent);
	static wxButton* CreateSevenButton(wxWindow* parent);
	static wxButton* CreateEightButton(wxWindow* parent);
	static wxButton* CreateNineButton(wxWindow* parent);
	static wxButton* CreateOpenParenthesesButton(wxWindow* parent);
	static wxButton* CreateClosingParenthesesButton(wxWindow* parent);

	static wxButton* CreateExponentButton(wxWindow* parent);
};

