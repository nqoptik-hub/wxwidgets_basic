#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <atomic>
#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <wx/wx.h>

enum WindowID : int
{
    ID_HELLO = 10001,
    ID_START_PRINTING_TIME,
    ID_STOP_PRINTING_TIME,
    ID_BUTTOM,
    ID_TEXT,
    ID_LIST,
};

class MainWindow : public wxFrame
{
private:
    std::atomic<bool> is_printing_time_;
    std::thread printing_time_thread_;

private:
    void on_hello(wxCommandEvent& WXUNUSED(event));
    void on_exit(wxCommandEvent& WXUNUSED(event));

    void on_start_printing_time(wxCommandEvent& WXUNUSED(event));
    void on_stop_printing_time(wxCommandEvent& WXUNUSED(event));

    void on_about(wxCommandEvent& WXUNUSED(event));

    static void create_printing_time_thread(MainWindow* this_object_ptr);
    void print_time();

    wxDECLARE_EVENT_TABLE();

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAIN_WINDOW_HPP
