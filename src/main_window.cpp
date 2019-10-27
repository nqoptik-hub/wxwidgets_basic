#include "wxwidgets_basic/main_window.hpp"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "SampleApplication", wxPoint(30, 30), wxSize(800, 600))
{
    button_ptr_ = new wxButton(this, BUTTOM_ID, "Click me", wxPoint(10, 10), wxSize(150, 50));
    text_ptr_ = new wxTextCtrl(this, TEXT_ID, "Text", wxPoint(10, 70), wxSize(300, 30));
    list_ptr_ = new wxListBox(this, LIST_ID, wxPoint(10, 110), wxSize(300, 300));
}

MainWindow::~MainWindow()
{
}
