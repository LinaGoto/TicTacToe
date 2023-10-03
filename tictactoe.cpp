#include <iostream>
#include <cstring>

using namespace std;

void printBoard(char board[3][3]);
bool checkWin(int player, char board[3][3]);
bool checkTie(char board[3][3]);

const int BLANK = 0;
const int XMOVE = 1;
const int OMOVE = 2;
const int XTURN = 0;
const int OTURN = 1;


int main(){

  int COUTX = 0;
  int COUTO = 0;
  int COUTT = 0;
  bool stillplaying = true;
  int TURN = XTURN;
  int row, column;

  char board[3][3];
  for (int j = 0; j < 3; j ++){
    for (int i = 0; i < 3; i ++){
      board[j][i] = BLANK;
     }
    }

  while (stillplaying == true){
    //input move
    cout << "input point: " << endl;
    char input[3];
    cin.get(input,3);
    cin.get();
    
    row    = input[0] - 'a';
    column = input[1] - '1';

    if ((row < 0) || (column < 0) || (row > 2) || (column > 2)) {
      cout << "enter a letter followed by a number" << endl;
    } else if (board[row][column] != 0) {
         cout << "The spot is not opened" << endl;
    } else {
       if (TURN == XTURN){
           board[row][column] = XMOVE;
           TURN = OTURN;
         } else {
           board[row][column] = OMOVE;
           TURN = XTURN;
         }
         printBoard(board);
    }

    //check for win
    if (checkWin(XMOVE, board) == true){
        cout << "X wins!" << endl;
        COUTX ++;
        cout << "X win: " << COUTX << endl;
        cout << "O win: " << COUTO << endl;
        cout << "Tie: " << COUTT << endl;
    }
    if (checkWin(OMOVE, board) == true){
        cout << "O wins!" << endl;
        COUTO ++;
        cout << "X win: " << COUTX << endl;
        cout << "O win: " << COUTO << endl;
        cout << "Tie: " << COUTT << endl;
    }
    if (checkTie(board) == true && checkWin(XMOVE, board) == false && checkWin(OMOVE, board) == false){
        cout << "Tie!" << endl;
        COUTT ++;
          cout << "X win: " << COUTX << endl;
        cout << "O win: " << COUTO << endl;
        cout << "Tie: " << COUTT << endl;
    }
    if (checkWin(XMOVE, board) == true || checkWin(OMOVE, board) == true || checkTie(board) == true){
    cout << "play again? y or n: " << endl;
    char play[3];
    cin.get(play, 3);
    cin.get();
    
    if (play[0] == 'y'){
        stillplaying = true;
        for (int j = 0; j < 3; j ++){
            for (int i = 0; i < 3; i ++){
            board[j][i] = BLANK;
            }
        }
        TURN = XTURN;
    }
    
    if (play[0] == 'n'){
        stillplaying = false;
    }
    }
  }
}

//checkwin
bool checkWin(int player, char board[3][3]){
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
        return true;
    }
    if (board[1][0] == player && board[1][1] ==player && board[1][2] == player) {
            return true;
    }
    if (board[2][0] == player && board[2][1] ==player && board[2][2] == player) {
        return true;
    }
    if (board[0][0] == player && board[1][0] ==player && board[2][0] == player) {
        return true;
    }
    if (board[0][1] == player && board[1][1] ==player && board[2][1] == player) {
        return true;
        }
    if (board[0][2] == player && board[1][2] ==player && board[2][2] == player) {
        return true;
    }
    if (board[0][0] == player && board[1][1] ==player && board[2][2] == player) {
        return true;
    }
    if (board[2][0] == player && board[1][1] ==player && board[0][2] == player) {
        return true;
    }
   return false;
}

//check tie
bool checkTie(char board[3][3]){
    for (int row=0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            if (board[row][column] == BLANK){
                return false;
            }
        }
    }
    return true;
}

//print the board
void printBoard(char board[3][3]){

  cout << " 123" << endl;
  for (int row = 0; row < 3; row++){
    char output[5];
    output[0] = 'a' + row;
    for (int column = 0; column < 3; column++){
      if (board[row][column] == BLANK){
        output[column + 1] = ' ';
      }
      if (board[row][column] == XMOVE){
        output[column + 1] = 'X';
      }
      if (board[row][column] == OMOVE){
        output[column + 1] = 'O';
      }
    output[4] = '\0';
    }
    cout << output << endl;
  }
}
