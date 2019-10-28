#include "wxwidgets_basic/main_window.hpp"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "SampleApplication", wxPoint(30, 30), wxSize(800, 600))
{
    index_ = 0;
    is_counting_ = false;

    // Menu file
    wxMenu* menu_file_ptr = new wxMenu();
    menu_file_ptr->Append(ID_HELLO, "&Hello\tCtrl-H", "Help string shown in status bar for this menu item");
    menu_file_ptr->AppendSeparator();
    menu_file_ptr->Append(wxID_EXIT);

    // Menu run
    wxMenu* menu_run_ptr = new wxMenu();
    menu_run_ptr->Append(ID_RUN, "&Run\tCtrl-R", "Run string");
    menu_run_ptr->AppendSeparator();
    menu_run_ptr->Append(ID_STOP, "&Stop\tCtrl-S", "Stop string");

    // Menu help
    wxMenu* menu_help_ptr = new wxMenu();
    menu_help_ptr->Append(wxID_ABOUT);

    // Menu bar
    wxMenuBar* menu_bar_ptr = new wxMenuBar();
    menu_bar_ptr->Append(menu_file_ptr, "&File");
    menu_bar_ptr->Append(menu_run_ptr, "&Run");
    menu_bar_ptr->Append(menu_help_ptr, "&Help");
    SetMenuBar(menu_bar_ptr);

    // Status bar
    CreateStatusBar();
    SetStatusText("Welcome to SampleApplication!");

    wxButton* button_ptr = new wxButton(this, ID_BUTTOM, "Click me", wxPoint(10, 10), wxSize(150, 50));
    wxTextCtrl* text_ptr = new wxTextCtrl(this, ID_TEXT, "Text", wxPoint(10, 70), wxSize(300, 30));
    wxListBox* list_ptr = new wxListBox(this, ID_LIST, wxPoint(10, 110), wxSize(300, 300));
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_hello(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox("Hello world from wxWidgets!", "Hello", wxOK | wxICON_INFORMATION);
}

void MainWindow::on_run(wxCommandEvent& WXUNUSED(event))
{
    if (!is_counting_)
    {
        is_counting_ = true;
        counting_thread_ = std::thread(create_counting_thread, this);
        wxMessageBox("Started running the counting thread!", "Run", wxOK | wxICON_INFORMATION);
    }
    else
    {
        wxMessageBox("The counting thread is already running!", "Warning", wxOK | wxICON_WARNING);
    }
}

void MainWindow::on_stop(wxCommandEvent& WXUNUSED(event))
{
    if (is_counting_)
    {
        is_counting_ = false;
        counting_thread_.detach();
        wxMessageBox("Stopped the counting thead!", "Stop", wxOK | wxICON_INFORMATION);
    }
    else
    {
        wxMessageBox("The counting thead is not runing!", "Warning", wxOK | wxICON_WARNING);
    }
}

void MainWindow::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox("This is a wxWidgets' sample application.", "About Sample Application", wxOK | wxICON_INFORMATION);
}

void MainWindow::on_exit(wxCommandEvent& WXUNUSED(event))
{
    if (is_counting_)
    {
        wxMessageBox("The counting thread is still running, please stop it before close the application!", "Warning", wxOK | wxICON_WARNING);
    }
    else
    {
        Close(true);
    }
}

void MainWindow::create_counting_thread(MainWindow* this_object_ptr)
{
    this_object_ptr->count_index();
}

void MainWindow::count_index()
{
    while (is_counting_)
    {
        printf("current index: %d\n", index_);
        ++index_;
        usleep(1000000);
    }
}
