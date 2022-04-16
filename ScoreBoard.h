
#ifndef YOUR_PROJECT_NAME_SCOREBOARD_H
#define YOUR_PROJECT_NAME_SCOREBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/dcbuffer.h>



class ScoreBoard {
private:
    wxRect boundary = wxRect(wxPoint(0, 5), wxPoint(480, 100));
    wxRect score_caption = wxRect(wxPoint(8, 0), wxPoint(120, 50));
    wxRect score_content = wxRect(wxPoint(8, 50), wxPoint(120, 100));
    wxRect best_caption = wxRect(wxPoint(120, 0), wxPoint(240, 50));
    wxRect best_content = wxRect(wxPoint(120, 50), wxPoint(240, 100));
public:
    ScoreBoard() {};

    void DrawScoreBoard(wxBufferedPaintDC &dc,
                  wxString &current, wxString &best) {
        dc.DrawRoundedRectangle(boundary, 8.0);

        dc.SetFont(wxFontInfo(20).Bold(2));

        dc.DrawLabel("SCORE", score_caption, wxALIGN_CENTER);
        dc.DrawLabel("BEST", best_caption, wxALIGN_CENTER);
        dc.SetFont(wxFontInfo(16).Bold(2));
        dc.DrawLabel(current, score_content, wxALIGN_CENTER);
        dc.DrawLabel(best, best_content, wxALIGN_CENTER);
    }

};


#endif //YOUR_PROJECT_NAME_SCOREBOARD_H
