#include <wx/wxprec.h>
#include <wx/wx.h>
#include "GameWindow.h"

class App_2048 : public wxApp{
private:
    GameWindow *window{};

public:
    bool OnInit() override{
        window = new GameWindow();
        window->setUp();
        return true;
    }
};

wxIMPLEMENT_APP(App_2048);



