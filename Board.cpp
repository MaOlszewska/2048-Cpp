#include <stdlib.h>
#include <string>
#include "Board.h"

Board::Board() {
    this->currentScore = 0;
    this->highestScore = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            this->cells[i][j] = 0;
        }
    }
}

bool Board::checkIsEmpty() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (cells[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

wxColour Board::GetCellColour(int row, int col) {
    switch (cells[row][col]) {
        case 0:
            return tilesColour[0];
        case 2:
            return tilesColour[1];
        case 4:
            return tilesColour[2];
        case 8:
            return tilesColour[3];
        case 16:
            return tilesColour[4];
        case 32:
            return tilesColour[5];
        case 64:
            return tilesColour[6];
        case 128:
            return tilesColour[7];
        case 256:
            return tilesColour[8];
        case 512:
            return tilesColour[9];
        case 1024:
            return tilesColour[10];
    }
}

void Board::drawCells(wxBufferedPaintDC &dc) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            wxRect rect(i * 120, j * 120+20, 120, 120);
            dc.SetBrush(GetCellColour(i, j));
            dc.DrawRoundedRectangle(rect, 10.0);

            wxString number;
            number << cells[i][j];
            dc.SetFont(wxFontInfo(number.Length() < 5 ? 20 : 16));
            dc.DrawLabel(number, rect, wxALIGN_CENTER);
        }
    }
}

void Board::Surprise(wxBufferedPaintDC &dc) {
    wxInitAllImageHandlers();
    wxImage img;
    img.LoadFile("pobrane.jpg");
    wxFrame* frame  = new wxFrame(NULL, wxID_ANY, "Surprise! You are a winner! ");
    wxStaticBitmap* bitmap = new wxStaticBitmap(frame, wxID_ANY, wxBitmap(img));
    frame ->Show();
}
void Board::move(int number) {
    int counter = 0;
    if (number == 0){

        for (int i = 0; i < 4; i++) {
            int currentX = i;
            for (int j = 3 ; j > 0; j--) {
                int currentY = j;
                int nextY = j - 1;
                if(cells[currentY][currentX] == cells[nextY][currentX]){
                    cells[nextY][currentX] += cells[currentY][currentX];
                    counter += cells[nextY][currentX];
                    cells[currentY][currentX] = 0;
                }
                else if(cells[nextY][currentX] == 0){
                    cells[nextY][currentX] = cells[currentY][currentX];
                    cells[currentY][currentX] = 0;
                }
            }
        }
    }
    else if(number == 1){
        for (int i = 0; i < 4 ; i++) {
            int currentX = i;
            for (int j = 0 ; j < 3; j++) {
                int currentY = j;
                int nextY = j + 1;
                if(cells[currentY][currentX] == cells[nextY][currentX]){
                    cells[nextY][currentX] += cells[currentY][currentX];
                    counter += cells[nextY][currentX];
                    cells[currentY][currentX] = 0;
                }
                else if(cells[nextY][currentX] == 0){
                    cells[nextY][currentX] = cells[currentY][currentX];
                    cells[currentY][currentX] = 0;
                }
            }
        }
    }
    else if(number == 2){
        for (int i = 3; i > 0 ; i--) {
            int currentX = i;
            int nextX = i - 1;
            for (int j = 3 ; j >= 0; j--) {
                int currentY = j;
                if(cells[currentY][currentX] == cells[currentY][nextX]){
                    cells[currentY][nextX] += cells[currentY][currentX];
                    counter += cells[currentY][nextX];
                    cells[currentY][currentX] = 0;
                }
                else if(cells[currentY][nextX] == 0){
                    cells[currentY][nextX] = cells[currentY][currentX];
                    cells[currentY][currentX] = 0;
                }
            }
        }
    }
    else if(number == 3){
        for (int i = 0; i < 3 ; i++) {
            int currentX = i;
            int nextX = i + 1;
            for (int j = 0 ; j < 4; j++) {
                int currentY = j;
                if(cells[currentY][currentX] == cells[currentY][nextX]){
                    cells[currentY][nextX] += cells[currentY][currentX];
                    counter += cells[currentY][nextX];
                    cells[currentY][currentX] = 0;
                }
                else if(cells[currentY][nextX] == 0){
                    cells[currentY][nextX] = cells[currentY][currentX];
                    cells[currentY][currentX] = 0;
                }
            }
        }
    }
    this->currentScore += counter;

    if(this->currentScore  >this -> highestScore){
        this->highestScore = this->currentScore;
    }
}

bool Board::add() {
    if(checkIsEmpty()){
        int random = rand() % 100;
        int added = 0;
        while(added < 100){
            int x = rand() % 4;
            int y = rand() % 4;
            if(cells[x][y] == 0){
                if(random % 2 == 0){
                    cells[x][y] = 2;
                }
                else{
                    cells[x][y] = 4;
                }
                return true;
            }
            added += 1;
        }
        return false;
    }
}

void Board::Restart() {
    for(int i = 0; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            cells[i][j] = 0;
        }
    }
}

bool Board::ifWin(){
    for(int i = 0; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            if(cells[i][j] == 2048){
                return true;
            }
        }
    }
    return false;
}