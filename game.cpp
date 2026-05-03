#include <iostream>
#include <vector>

using namespace std;

bool move (bool red_playing, vector<vector<int>>& board, int rows, int line, int tks){

    int i;
    bool line_full = true;
    for (i = rows-1; i >= 0 && line_full == true; i--){
        if (board[i][line] == 0){
            if (red_playing) board[i][line] = 1;
            else board[i][line] = 2;
            line_full = false;
        }
    }
    i++;

    if (line_full) return false;

}


void display_board(int n, int m){
    for (int i = 0; i < n; i ++){
        cout<<endl<<"|";
        for (int j = 0; j < m; j++){
            cout<<"   |";
        }
        cout<<endl<<"|";
        for (int j = 0; j < m; j++){
                cout<<"---|";
            }
    }
    cout<<endl<<endl;
}

int main() {

    unsigned int rows, cols, tks, line;
    bool winner = false, red_playing = true;

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
        display_board(rows, cols);

        while (true){
            try{
                // Error Handling Move
                cout<< (red_playing ? "Red" : "Yellow");
                cout<<" to play! \nYour move: "; 
                cin>>line;
                if (line > cols || line == 0) throw invalid_argument("");

                winner = move(red_playing, board, rows, line-1, tks);
                red_playing = !red_playing;
                break;
            } catch (const exception& e) {}
        }
    }while (!winner);
   

}