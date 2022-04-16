#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
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
    wxColour getCellColour(int row, int col);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool add();
    void restart();
    void resetScore(){ currentScore = 0;}
    bool checkWin();
    void surprise(wxBufferedPaintDC &dc);
    void checkScore(int current);
};



