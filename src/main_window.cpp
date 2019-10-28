#include "wxwidgets_basic/main_window.hpp"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "SampleApplication", wxPoint(30, 30), wxSize(800, 600))
{
    // Menu file
    wxMenu* menu_file_ptr = new wxMenu();
    menu_file_ptr->Append(ID_HELLO, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menu_file_ptr->AppendSeparator();
    menu_file_ptr->Append(wxID_EXIT);

    // Menu help
    wxMenu* menu_help_ptr = new wxMenu();
    menu_help_ptr->Append(wxID_ABOUT);

    // Menu bar
    wxMenuBar* menu_bar_ptr = new wxMenuBar();
    menu_bar_ptr->Append(menu_file_ptr, "&File");
    menu_bar_ptr->Append(menu_help_ptr, "&Help");
    SetMenuBar(menu_bar_ptr);

    // Status bar
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    wxButton* button_ptr = new wxButton(this, ID_BUTTOM, "Click me", wxPoint(10, 10), wxSize(150, 50));
    wxTextCtrl* text_ptr = new wxTextCtrl(this, ID_TEXT, "Text", wxPoint(10, 70), wxSize(300, 30));
    wxListBox* list_ptr = new wxListBox(this, ID_LIST, wxPoint(10, 110), wxSize(300, 300));
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_hello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MainWindow::on_about(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' sample application", "About Sample Application", wxOK | wxICON_INFORMATION);
}

void MainWindow::on_exit(wxCommandEvent& event)
{
    Close(true);
}
