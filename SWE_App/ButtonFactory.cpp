#include "ButtonFactory.h"

wxSize* ButtonFactory::ButtonSize = new wxSize();

wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint position)
{
    return new wxButton(parent, id, label, position, *ButtonSize);
}

wxButton* ButtonFactory::CreateButton(wxWindow* parent, const char& label)
{
    return CreateButton(parent, (unsigned int)label, label);
}

wxButton* ButtonFactory::CreateButton(wxWindow* parent, unsigned int label)
{
    return CreateButton(parent, label, std::to_string(label));
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
    return CreateButton(parent, '+');
}

wxButton* ButtonFactory::CreateMinusButton(wxWindow* parent)
{
    return CreateButton(parent, '-');
}

wxButton* ButtonFactory::CreateMultButton(wxWindow* parent)
{
    return CreateButton(parent, '*');
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent)
{
    return CreateButton(parent, '/');
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
    return CreateButton(parent, '%');
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, wxWindowID id)
{
    return CreateButton(parent, id, 'C');
}

wxButton* ButtonFactory::CreateDeleteButton(wxWindow* parent, wxWindowID id)
{
    return CreateButton(parent, id, "Del");
}

wxButton* ButtonFactory::CreateSinButton(wxWindow* parent, wxWindowID id)
{
    return CreateButton(parent, id, "Sin(x)");
}

wxButton* ButtonFactory::CreateCosineButton(wxWindow* parent, wxWindowID id)
{
    return CreateButton(parent, id, "Cos(x)");
}

wxButton* ButtonFactory::CreateTangentButton(wxWindow* parent, wxWindowID id)
{
    return CreateButton(parent, id, "Tan(x)");
}

wxButton* ButtonFactory::CreateEqualButton(wxWindow* parent)
{
    return CreateButton(parent, '=');
}

wxButton* ButtonFactory::CreateZeroButton(wxWindow* parent)
{
    return CreateButton(parent, 0U);
}

wxButton* ButtonFactory::CreateOneButton(wxWindow* parent)
{
    return CreateButton(parent, 1U);
}

wxButton* ButtonFactory::CreateTwoButton(wxWindow* parent)
{
    return CreateButton(parent, 2U);
}

wxButton* ButtonFactory::CreateThreeButton(wxWindow* parent)
{
    return CreateButton(parent, 3U);
}

wxButton* ButtonFactory::CreateFourButton(wxWindow* parent)
{
    return CreateButton(parent, 4U);
}

wxButton* ButtonFactory::CreateFiveButton(wxWindow* parent)
{
    return CreateButton(parent, 5U);
}

wxButton* ButtonFactory::CreateSixButton(wxWindow* parent)
{
    return CreateButton(parent, 6U);
}

wxButton* ButtonFactory::CreateSevenButton(wxWindow* parent)
{
    return CreateButton(parent, 7U);
}

wxButton* ButtonFactory::CreateEightButton(wxWindow* parent)
{
    return CreateButton(parent, 8U);
}

wxButton* ButtonFactory::CreateNineButton(wxWindow* parent)
{
    return CreateButton(parent, 9U);
}

wxButton* ButtonFactory::CreateOpenParenthesesButton(wxWindow* parent)
{
    return CreateButton(parent, '(');
}

wxButton* ButtonFactory::CreateClosingParenthesesButton(wxWindow* parent)
{
    return CreateButton(parent, ')');
}

wxButton* ButtonFactory::CreateExponentButton(wxWindow* parent)
{
    return CreateButton(parent, '^');
}
