#include "wxwidgets_basic/sample_application.hpp"

wxIMPLEMENT_APP(SampleApplication);

SampleApplication::SampleApplication()
{
}

SampleApplication::~SampleApplication()
{
}

bool SampleApplication::OnInit()
{
    MainWindow* main_window = new MainWindow();
    wxIcon      icon("../assets/icon/2019_05_nq.png");
    main_window->SetIcon(icon);
    main_window->Show(true);
    return true;
}
