#include "wxwidgets_basic/sample_application.hpp"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(ID_HELLO, MainWindow::on_hello)
        EVT_MENU(wxID_EXIT, MainWindow::on_exit)

            EVT_MENU(ID_START_PRINTING_TIME, MainWindow::on_start_printing_time)
                EVT_MENU(ID_STOP_PRINTING_TIME, MainWindow::on_stop_printing_time)

                    EVT_MENU(wxID_ABOUT, MainWindow::on_about)
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
    MainWindow* main_window = new MainWindow();
    main_window->Show(true);
    return true;
}
