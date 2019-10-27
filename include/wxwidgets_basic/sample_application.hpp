#ifndef SAMPLE_APPLICATION_HPP
#define SAMPLE_APPLICATION_HPP

#include <wx/wx.h>

#include "wxwidgets_basic/main_window.hpp"

class SampleApplication : public wxApp
{
private:
    MainWindow* main_window_ = nullptr;

public:
    SampleApplication();
    ~SampleApplication();

    bool OnInit() override;
};

#endif // SAMPLE_APPLICATION_HPP
