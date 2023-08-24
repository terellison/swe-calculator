#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    calculator = new Calculator();

    calculator->Show();

    return true;
}
