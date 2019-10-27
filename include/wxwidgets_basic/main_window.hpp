#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <wx/wx.h>

enum WindowID : int
{
    BUTTOM_ID = 0,
    TEXT_ID = 1,
    LIST_ID = 2
};

class MainWindow : public wxFrame
{
private:
    wxButton* button_ptr_ = nullptr;
    wxTextCtrl* text_ptr_ = nullptr;
    wxListBox* list_ptr_ = nullptr;

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAIN_WINDOW_HPP
