#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/dcbuffer.h>

class ScoreBoard {

private:
    wxRect boundary = wxRect(wxPoint(0, 5), wxPoint(480, 100));
    wxRect scoreLabel = wxRect(wxPoint(8, 0), wxPoint(120, 50));
    wxRect score = wxRect(wxPoint(8, 50), wxPoint(120, 100));
    wxRect highestLabel = wxRect(wxPoint(120, 0), wxPoint(240, 50));
    wxRect highest = wxRect(wxPoint(120, 50), wxPoint(240, 100));

public:
    ScoreBoard() {};
    void DrawScoreBoard(wxBufferedPaintDC &dc,wxString &current, wxString &best);
};