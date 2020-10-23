#include "wxwidgets_basic/main_window.hpp"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    wxEND_EVENT_TABLE();

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "SampleApplication", wxPoint(100, 100), wxSize(800, 600))
{
    is_printing_time_ = false;

    // Menu file
    wxMenu* menu_file_ptr = new wxMenu();
    menu_file_ptr->Append(ID_MENU_HELLO, "&Hello\tCtrl-H", "Help string shown in status bar for this menu item");
    menu_file_ptr->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::on_hello, this, ID_MENU_HELLO);

    menu_file_ptr->AppendSeparator();
    menu_file_ptr->Append(wxID_EXIT);
    menu_file_ptr->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::on_exit, this, wxID_EXIT);

    // Menu time
    wxMenu* menu_time_ptr = new wxMenu();
    menu_time_ptr->Append(ID_MENU_START_PRINTING_TIME, "&Start printing time\tCtrl-P", "Start printing");
    menu_time_ptr->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::on_start_printing_time, this, ID_MENU_START_PRINTING_TIME);

    menu_time_ptr->AppendSeparator();
    menu_time_ptr->Append(ID_MENU_STOP_PRINTING_TIME, "&Stop printing time\tCtrl-S", "Stop printing");
    menu_time_ptr->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::on_stop_printing_time, this, ID_MENU_STOP_PRINTING_TIME);

    // Menu help
    wxMenu* menu_help_ptr = new wxMenu();
    menu_help_ptr->Append(wxID_ABOUT);
    menu_help_ptr->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::on_about, this, wxID_ABOUT);

    // Menu bar
    wxMenuBar* menu_bar_ptr = new wxMenuBar();
    menu_bar_ptr->Append(menu_file_ptr, "&File");
    menu_bar_ptr->Append(menu_time_ptr, "&Time");
    menu_bar_ptr->Append(menu_help_ptr, "&Help");
    SetMenuBar(menu_bar_ptr);

    // Status bar
    CreateStatusBar();
    SetStatusText("Welcome to SampleApplication!");

    text_ptr_ = new wxTextCtrl(this, wxID_ANY, "Sample text", wxPoint(10, 70), wxSize(300, 30));
    button_ptr_ = new wxButton(this, ID_BUTTON_CLICK_ME, "Click me", wxPoint(10, 10), wxSize(150, 50));
    button_ptr_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainWindow::on_click_me, this, ID_BUTTON_CLICK_ME);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_hello(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox("Hello world from wxWidgets!", "Hello", wxOK | wxICON_INFORMATION);
}

void MainWindow::on_exit(wxCommandEvent& WXUNUSED(event))
{
    if (is_printing_time_)
    {
        wxMessageBox("The time printer is still running, please stop it before close the application!", "Warning", wxOK | wxICON_WARNING);
    }
    else
    {
        Close(true);
    }
}

void MainWindow::on_start_printing_time(wxCommandEvent& WXUNUSED(event))
{
    if (!is_printing_time_)
    {
        is_printing_time_ = true;
        printing_time_thread_ = std::thread(create_printing_time_thread, this);
        wxMessageBox("Started printing time!", "Time", wxOK | wxICON_INFORMATION);
    }
    else
    {
        wxMessageBox("The time printer is already running!", "Warning", wxOK | wxICON_WARNING);
    }
}

void MainWindow::on_stop_printing_time(wxCommandEvent& WXUNUSED(event))
{
    if (is_printing_time_)
    {
        is_printing_time_ = false;
        printing_time_thread_.detach();
        wxMessageBox("Stopped printing time!", "Time", wxOK | wxICON_INFORMATION);
    }
    else
    {
        wxMessageBox("The time printer is not runing!", "Warning", wxOK | wxICON_WARNING);
    }
}

void MainWindow::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox("This is a wxWidgets' sample application.", "About Sample Application", wxOK | wxICON_INFORMATION);
}

void MainWindow::on_click_me(wxCommandEvent& WXUNUSED(event))
{
    wxString text_content = text_ptr_->GetValue();
    printf("%s\n", text_content.mb_str().data());
    wxMessageBox(text_content, "Click me", wxOK | wxICON_INFORMATION);
}

void MainWindow::create_printing_time_thread(MainWindow* this_object_ptr)
{
    this_object_ptr->print_time();
}

void MainWindow::print_time()
{
    while (is_printing_time_)
    {
        std::time_t time_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        printf("%s", std::ctime(&time_now));
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
