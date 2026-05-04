#include <iostream>
#include <vector>

using namespace std;

bool move (bool red_playing, vector<vector<int>>& board, int rows, int cols, int line, int tks){

    // Place a token on a pile of tokens
    int i, j, k, counter;
    for (i = rows-1; i >= 0; i--)
        if (board[i][line] == 0){
            if (red_playing) board[i][line] = 1;
            else board[i][line] = 2;
            break;
        }

    // Horizontal
    counter = 0;
    j = line;
    while (j < cols && board[i][j] == (red_playing ? 1 : 2)){counter++; j++;} if (counter >= tks) return true;
    j = line -1;
    while (j >= 0 && board[i][j] == (red_playing ? 1 : 2)){counter++; j--;} if (counter >= tks) return true;
    
    // Vertical
    counter = 0;
    j = i;
    while (j >= 0 && board[j][line] == (red_playing ? 1 : 2)){counter++; j--;} if (counter >= tks) return true;
    j = i + 1;
    while (j < rows && board[j][line] == (red_playing ? 1 : 2)){counter++; j++;} if (counter >= tks) return true;
    
    // Primary diagonal
    counter = 0;
    j = line; k = i;
    while (k < rows && j < cols && board[k][j] == (red_playing ? 1 : 2)){counter++; k++; j++;} if (counter >= tks) return true;
    j = line - 1; k = i - 1;
    while (k >= 0 && j >= 0 && board[k][j] == (red_playing ? 1 : 2)){counter++; k--; j--;} if (counter >= tks) return true;

    // Secondary diagonal
    counter = 0;
    j = line; k = i;
    while (k >= 0 && j < cols && board[k][j] == (red_playing ? 1 : 2)){counter++; k--; j++;} if (counter >= tks) return true;
    j = line - 1; k = i + 1;
    while (k < rows && j >= 0 && board[k][j] == (red_playing ? 1 : 2)) {counter++; k++; j--;} if (counter >= tks) return true;
    
    return false;
}

void display_board(int n, int m, vector<vector<int>>& board){
    for (int i = 0; i < n; i ++){
        cout<<endl<<"|";
        for (int j = 0; j < m; j++){
            if (board[i][j] == 1)      cout<<" R |";
            else if (board[i][j] == 2) cout<<" Y |";
            else                       cout<<"   |";
        }
        cout<<endl<<"|";
        for (int j = 0; j < m; j++)    cout<<"---|";
    }
    cout<<endl<<endl;
}

int main() {

    unsigned int rows, cols, tks, line;
    bool winner = false, red_playing = true;

    // Main menu
    while (true){
        try{
            cout<<"|||---Welcome to Connect 4!---|||\n\n";
            cout<<"Please enter the number of rows: "; cin>>rows;
            cout<<"Please enter the number of columns: "; cin>>cols;
            cout<<"Please enter the number of winning tokens: "; cin>>tks;
            break;
        }catch (exception e) {cout<<"Invalid input\n";}
    }  

    vector<vector<int>> board(rows, vector<int>(cols, 0));

    do {

        system("CLS");
        display_board(rows, cols, board);

        // Making sure the move is introduced correctly before checking for win
        while (true){
            try{
                // Error Handling Move
                cout<< (red_playing ? "Red" : "Yellow");
                cout<<" to play! \nYour move: "; 
                cin>>line;
                if (line > cols || line == 0 || board[0][line-1] != 0) throw invalid_argument("");
                
                winner = move(red_playing, board, rows, cols, line-1, tks);
                red_playing = !red_playing;
                break;
            } catch (const exception& e) {cout<<"\nIndex out of bounds!\n";}
        }
    }while (!winner);
   
    if (winner){
        system("CLS");
        display_board(rows, cols, board);
        cout<< (red_playing ? "YELLOW" : "RED")<<" WIN!!!!!!";
    }
}