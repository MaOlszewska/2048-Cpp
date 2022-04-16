#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/dcbuffer.h>


class Board {
private:
    int cells[4][4];
    int currentScore;
    int highestScore;

    wxColour tilesColour[16] ={
            wxColour("#ffffff"), wxColour("#ffd9f8"),
            wxColour("#ffc1f4"), wxColour("#ffa8ef"),
            wxColour("#ff9bed"), wxColour("#ff83e9"),
            wxColour("#ff83e9"), wxColour("#cc68ba"),
            wxColour("#b25ba3"), wxColour("#994e8b"),
            wxColour("#7f4174"), wxColour("#66345d"),
    };

public:
    Board();
    int getCurrrentScore(){ return currentScore; }
    int getHighestScore(){ return highestScore; }

    bool checkIsEmpty();
    void drawCells(wxBufferedPaintDC &dc);
    wxColour GetCellColour(int row, int col);
    void move(int number);
    bool add();
    void Restart();
    void zeroScore(){ currentScore = 0;}
    bool ifWin();
    void Surprise(wxBufferedPaintDC &dc);
};


#endif //YOUR_PROJECT_NAME_BOARD_H
