#include "ScoreBoard.h"

void ScoreBoard::DrawScoreBoard(wxBufferedPaintDC &dc, wxString &current, wxString &best) {
    dc.DrawRoundedRectangle(boundary, 8.0);
    dc.SetFont(wxFontInfo(20).Bold(2));
    dc.DrawLabel("SCORE", scoreLabel, wxALIGN_CENTER);
    dc.DrawLabel("BEST", highestLabel, wxALIGN_CENTER);
    dc.SetFont(wxFontInfo(16).Bold(2));
    dc.DrawLabel(current, score, wxALIGN_CENTER);
    dc.DrawLabel(best, highest, wxALIGN_CENTER);
}
