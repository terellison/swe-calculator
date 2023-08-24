#pragma once
#include "wx\wx.h"
#include "Calculator.h"
class App : public wxApp
{
	Calculator* calculator = nullptr;

public:
	virtual bool OnInit();
};

