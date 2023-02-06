/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class TicTacToe {
    private:
        int map[3][3];
        int userColumn;
        int userRow;
        int machineColumn;
        int machineRow;
        
    public:
        TicTacToe() {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    map[i][j] = 0;
                }
            }
            
            srand(time(0));
        }
        void userFill() {
            //intentionally did backwards as I programmed it that way
            cout << "what row: ";
            cin >> userRow;
            cout << "what column: ";
            cin >> userColumn;
            while (checkInvalid(userRow-1, userColumn-1) == true) {
                cout << "\nSorry, that point is invalid. Please select another point: \n";
                cout << "what row: ";
                cin >> userRow;
                cout << "what column: ";
                cin >> userColumn;
            }
            map[userRow-1][userColumn-1] = 1;
        }
        void machineFill() {
            int machineRow = (rand() % 3);
            int machineColumn = (rand() % 3);
            while (checkInvalid(machineRow, machineColumn) == true) {
                machineRow = (rand() % 3);
                machineColumn = (rand() % 3);
            }
            map[machineRow][machineColumn] = -1;
        };
        void print() {
            for (int i = 0; i < 3; ++i) {
                cout << "   ";
                for (int j = 0; j < 3; ++j) {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }
        }
        void endScreen(int player) {
            if (checkWinForPlayer(player) == true) {
                cout << "\ncongratulations, you have bested your opponent.\n";
            }
            else {
                cout << "\nyou failed.\n";
            }
        }
        bool checkInvalid(int row, int column) {
            //cout << "\ncolumn: " << column+1 << " row: " << row+1 << endl;
            if (map[row][column] != 0) {return true;}
            if( (row > 2 || row < 0) || (column > 2 || column < 0) ) {return true;}
            return false;
        }
        bool checkWinForPlayer(int player) {
            bool win = false;
            // checking each row
            int i = 0;
            while ( (i < 3) && win != true) {
                int j = 0;
                win = true;
                //cout << "\nwin?";
                while ( (win == true) && (j<3)) {
                    if (map[i][j] != player) {win = false;} 
                    else {win = true;}
                    //cout << ": " << map[i][j];
                    ++j;
                }
                ++i;
            }
            //cout << " \nwin: " << win;
            
            if (win == false) {
                //checks each column
                i = 0;
                while ( (i < 3) && win != true) {
                    int j = 0;
                    win = true;
                    //cout << "\nwin?";
                    while ( (win == true) && (j<3)) {
                        if (map[j][i] != player) {win = false;} 
                        else {win = true;}
                        //cout << ": " << map[i][j];
                        ++j;
                    }
                    ++i;
                }
            }
            
            //checking diagonally from left to right
            if (win == false) {
                i = 0;
                win = true;
                while (win && i < 3) {
                    if (map[i][i] != player) {win = false;}
                    else {win = true;}
                    ++i;
                }
            }
            //checking diagonally from right to left
            if (win == false) {
                int i = 0;
                int j = 2;
                win = true;
                while (win && i < 3 && j >= 0) {
                    if (map[i][j] != player) {win = false;}
                    else {win = true;}
                    ++i;
                    --j;
                }
            }
            
            //cout << endl;
            return win;
        }
};

int main() {
    string wantsToPlay;
    
    cout << "\nDo you want to play a game? ";
    cin >> wantsToPlay;
    while(wantsToPlay != "y" && wantsToPlay != "n") {
        cout << "\nInvalid user input. Please enter y or n: ";
        cin >> wantsToPlay;
    }
    
    while(wantsToPlay == "y") {
        TicTacToe* board = new TicTacToe;

        while(board->checkWinForPlayer(-1) == false  &&  board->checkWinForPlayer(1) == false) {
            board->print();
            board->userFill();
            board->machineFill();
            //cout << board.checkWinForPlayer(1) << endl;
        }
        
        board->print();

        board->endScreen(1);

        delete board;

        cout << "\nDo you want to play again? ";
        cin >> wantsToPlay;
        while(wantsToPlay != "y" && wantsToPlay != "n") {
            cout << "\nInvalid user input. Please enter y or n: ";
            cin >> wantsToPlay;
        }
    }

    return 0;
}
