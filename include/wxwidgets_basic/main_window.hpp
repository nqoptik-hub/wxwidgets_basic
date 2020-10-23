#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <atomic>
#include <chrono>
#include <thread>
#include <wx/wx.h>

enum WindowID : int
{
    ID_MENU_HELLO = wxID_HIGHEST + 1,
    ID_MENU_START_PRINTING_TIME,
    ID_MENU_STOP_PRINTING_TIME,
    ID_BUTTON_CLICK_ME
};

class MainWindow : public wxFrame
{
private:
    std::atomic<bool> is_printing_time_;
    std::thread printing_time_thread_;

    wxTextCtrl* text_ptr_;
    wxButton* button_ptr_;

private:
    void on_hello(wxCommandEvent& WXUNUSED(event));
    void on_exit(wxCommandEvent& WXUNUSED(event));

    void on_start_printing_time(wxCommandEvent& WXUNUSED(event));
    void on_stop_printing_time(wxCommandEvent& WXUNUSED(event));

    void on_about(wxCommandEvent& WXUNUSED(event));

    void on_click_me(wxCommandEvent& WXUNUSED(event));

    static void create_printing_time_thread(MainWindow* this_object_ptr);
    void print_time();

    wxDECLARE_EVENT_TABLE();

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAIN_WINDOW_HPP
