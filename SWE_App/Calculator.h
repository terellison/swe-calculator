#pragma once
#include "wx/wx.h"
#include "ButtonIDDefines.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 800
#define NUMBER_BOX_HEIGHT 100
#define FONT_SIZE 50

class Calculator : public wxFrame
{
	wxTextCtrl* NumberBox = nullptr;

	std::vector<wxButton*> Buttons{};

	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* row1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* row2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* row3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* row4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* row5 = new wxBoxSizer(wxHORIZONTAL);

	void SetupRow1();
	void SetupRow2();
	void SetupRow3();
	void SetupRow4();
	void SetupRow5();

	void OnButtonClicked(wxCommandEvent& evt);

	void OnEqualButtonClicked(wxCommandEvent& evt);

	wxButton* GetButtonInstanceByID(wxWindowID id);

public:
	Calculator();

	wxDECLARE_EVENT_TABLE();
};

