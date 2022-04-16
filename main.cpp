
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "GameWindow.h"



#endif

class App_2048 : public wxApp
{
private:
    GameWindow *window;
public:
    virtual bool OnInit(){
        window = new GameWindow();
        window->setUp();
        return true;
    }
};

wxIMPLEMENT_APP(App_2048);



