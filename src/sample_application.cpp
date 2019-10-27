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
    main_window_ = new MainWindow();
    main_window_->Show(true);
    return true;
}
