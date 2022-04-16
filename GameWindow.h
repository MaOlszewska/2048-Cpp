#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
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

    void Restart(wxCommandEvent & event){
        SetStatusText("Play in 2048!");
        board.Restart();
        board.add();
        board.add();
        board.zeroScore();
        Refresh();
    }

    void GameStart() {
        srand((unsigned)time(NULL));
    }

    void setUp(){

        board.add();
        board.add();
        GameStart();

        Show(true);

    }
    void ButtonLeftClicked(wxCommandEvent & event){
        board.move(0);
        if(!board.add()){
            SetStatusText(wxString("Game Over!"));
        };
        if(board.ifWin()){
            SetStatusText(wxString("You are the best! "));
        };
        Refresh();
    }
    void ButtonUpClicked(wxCommandEvent & event){
        board.move(2);
        if(!board.add()){
            SetStatusText(wxString("Game Over!"));
        };
        if(board.ifWin()){
            SetStatusText(wxString("You are the best! "));
        };
        Refresh();
    }
    void ButtonDownClicked(wxCommandEvent & event){
        board.move(3);
        if(!board.add()){
            SetStatusText(wxString("Game Over!"));
        };
        if(board.ifWin()){
            SetStatusText(wxString("You are the best! "));
        };
        Refresh();
    }
    void ButtonRightClicked(wxCommandEvent & event){
        board.move(1);
        if(!board.add()){
            SetStatusText(wxString("Game Over!"));
        };
        if(board.ifWin()){
            SetStatusText(wxString("You are the best! "));
        };
        Refresh();
    }
    void OnPaint( wxPaintEvent &event ) {
        wxBufferedPaintDC dc(this);
        dc.Clear();

        wxString score, best;
        best << board.getHighestScore();
        score << board.getCurrrentScore();

        dc.SetPen(wxPen(background, 4));
        dc.SetBrush(wxColour("#c6e2ff"));

        dc.SetDeviceOrigin(7, 0);
        scoreBoard.DrawScoreBoard(dc, score, best);

        dc.SetTextForeground(background);
        dc.SetDeviceOrigin(7, 100);
        if(board.ifWin()){
            board.Surprise(dc);
            SetStatusText("Play in 2048!");
            board.Restart();
            board.add();
            board.add();
            board.zeroScore();
            Refresh();
        }
        else{
            board.drawCells(dc);
        }
    }

};


