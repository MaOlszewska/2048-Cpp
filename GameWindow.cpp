#include <wx/wxprec.h>
#include <wx/wx.h>
#include "GameWindow.h"
#include <string.h>
#include <wx/frame.h>

GameWindow::GameWindow() : wxFrame(
        NULL, wxID_ANY, "2048",
        wxDefaultPosition, wxSize(495, 700),
        wxDEFAULT_FRAME_STYLE ^ wxMAXIMIZE_BOX ^ wxRESIZE_BORDER) {

    CentreOnScreen();
    SetBackgroundColour(wxColour("#fff2c7"));
    CreateStatusBar();
    SetStatusText("Play in 2048!");
    wxButton *buttonUp = new wxButton(this, wxID_ANY, "UP", wxPoint(350,15),wxSize(60,30));
    wxButton *buttonDown= new wxButton(this, wxID_ANY, "DOWN", wxPoint(350,55),wxSize(60,30));
    wxButton *buttonLeft = new wxButton(this, wxID_ANY, "LEFT", wxPoint(280,55),wxSize(60,30));
    wxButton *buttonRight = new wxButton(this, wxID_ANY, "RIGHT", wxPoint(420,55),wxSize(60,30));
    wxButton *buttonRestart = new wxButton(this, wxID_ANY, "RESTART", wxPoint(210,610),wxSize(80,30));
    Bind(wxEVT_PAINT, &GameWindow::OnPaint, this);

    buttonUp->Bind(wxEVT_BUTTON, &GameWindow::ButtonUpClicked, this);
    buttonRight->Bind(wxEVT_BUTTON, &GameWindow::ButtonRightClicked, this);
    buttonDown->Bind(wxEVT_BUTTON, &GameWindow::ButtonDownClicked, this);
    buttonLeft->Bind(wxEVT_BUTTON, &GameWindow::ButtonLeftClicked, this);
    buttonRestart->Bind(wxEVT_BUTTON, &GameWindow::Restart, this);

    buttonUp->SetBackgroundColour(wxColour("#c7e5b9"));
    buttonDown->SetBackgroundColour(wxColour("#c7e5b9"));
    buttonLeft->SetBackgroundColour(wxColour("#c7e5b9"));
    buttonRight->SetBackgroundColour(wxColour("#c7e5b9"));
    buttonRestart->SetBackgroundColour(wxColour("#C3B6FF"));

}

void GameWindow::Restart(wxCommandEvent &event) {
    SetStatusText("Play in 2048!");
    board.restart();
    board.add();
    board.add();
    board.resetScore();
    Refresh();
}

void GameWindow::setUp() {
    board.add();
    board.add();
    Show(true);
}

void GameWindow::ButtonLeftClicked(wxCommandEvent &event) {
    board.moveLeft();
    if(!board.add()){SetStatusText(wxString("Game Over!"));}
    if(board.checkWin()){SetStatusText(wxString("You are the best! "));}
    Refresh();
}

void GameWindow::ButtonUpClicked(wxCommandEvent &event) {
    board.moveUp();
    if(!board.add()){SetStatusText(wxString("Game Over!"));}
    if(board.checkWin()){SetStatusText(wxString("You are the best! "));}
    Refresh();
}

void GameWindow::ButtonDownClicked(wxCommandEvent &event) {
    board.moveDown();
    if(!board.add()){SetStatusText(wxString("Game Over!"));}
    if(board.checkWin()){SetStatusText(wxString("You are the best! "));}
    Refresh();
}

void GameWindow::ButtonRightClicked(wxCommandEvent &event) {
    board.moveRight();
    if(!board.add()){SetStatusText(wxString("Game Over!"));}
    if(board.checkWin()){SetStatusText(wxString("You are the best! "));}
    Refresh();
}

void GameWindow::OnPaint(wxPaintEvent &event) {
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
    if(board.checkWin()){
        board.surprise(dc);
        SetStatusText("Play in 2048!");
        board.restart();
        board.add();
        board.add();
        board.resetScore();
        Refresh();
    }
    else board.drawCells(dc);
}








