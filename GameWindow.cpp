
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "GameWindow.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wx/wxprec.h>
#include <wx/wx.h>

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








