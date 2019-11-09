#include "wxwidgets_basic/sample_application.hpp"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    // File
    EVT_MENU(ID_MENU_HELLO, MainWindow::on_hello)
        EVT_MENU(wxID_EXIT, MainWindow::on_exit)
    // Time
    EVT_MENU(ID_MENU_START_PRINTING_TIME, MainWindow::on_start_printing_time)
        EVT_MENU(ID_MENU_STOP_PRINTING_TIME, MainWindow::on_stop_printing_time)
    // Help
    EVT_MENU(wxID_ABOUT, MainWindow::on_about)
    // Button
    EVT_BUTTON(ID_BUTTON_CLICK_ME, MainWindow::on_click_me)
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
    wxIcon icon("../assets/icon/2019_05_nq.png");
    main_window->SetIcon(icon);
    main_window->Show(true);
    return true;
}
