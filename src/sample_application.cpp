#include "wxwidgets_basic/sample_application.hpp"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(ID_HELLO, MainWindow::on_hello)
        EVT_MENU(wxID_ABOUT, MainWindow::on_about)
            EVT_MENU(ID_RUN, MainWindow::on_run)
                EVT_MENU(ID_STOP, MainWindow::on_stop)
                    EVT_MENU(wxID_EXIT, MainWindow::on_exit)
                        wxEND_EVENT_TABLE();

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
