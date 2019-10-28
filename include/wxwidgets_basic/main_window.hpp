#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <atomic>
#include <thread>
#include <wx/wx.h>

enum WindowID : int
{
    ID_HELLO = 10001,
    ID_RUN,
    ID_STOP,
    ID_BUTTOM,
    ID_TEXT,
    ID_LIST,
};

class MainWindow : public wxFrame
{
private:
    int index_;
    std::atomic<bool> is_counting_;
    std::thread counting_thread_;

private:
    void on_hello(wxCommandEvent& WXUNUSED(event));
    void on_about(wxCommandEvent& WXUNUSED(event));
    void on_run(wxCommandEvent& WXUNUSED(event));
    void on_stop(wxCommandEvent& WXUNUSED(event));
    void on_exit(wxCommandEvent& WXUNUSED(event));

    static void create_counting_thread(MainWindow* this_object_ptr);
    void count_index();

    wxDECLARE_EVENT_TABLE();

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAIN_WINDOW_HPP
