#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include "Board.h"
#include "ScoreBoard.h"

class GameWindow : public wxFrame {

private:
    wxColour background = wxColour("#FAFAFA");
    Board board = Board();
    ScoreBoard scoreBoard = ScoreBoard();

public:
    GameWindow();
    void Restart(wxCommandEvent & event);
    void setUp();
    void ButtonLeftClicked(wxCommandEvent & event);
    void ButtonUpClicked(wxCommandEvent & event);
    void ButtonDownClicked(wxCommandEvent & event);
    void ButtonRightClicked(wxCommandEvent & event);
    void OnPaint( wxPaintEvent &event );
};


