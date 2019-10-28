#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <wx/wx.h>

enum WindowID : int
{
    ID_BUTTOM = 10001,
    ID_TEXT,
    ID_LIST,
    ID_HELLO
};

class MainWindow : public wxFrame
{
private:
    void on_hello(wxCommandEvent& event);
    void on_about(wxCommandEvent& event);
    void on_exit(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAIN_WINDOW_HPP
