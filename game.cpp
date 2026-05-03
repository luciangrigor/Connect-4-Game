#include <iostream>

using namespace std;


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
}


int main() {


    int rows, cols, w;

    cout<<"---Welcome to Connect 4!---"<<endl;
    cout<<"Please enter the number of rows: "; cin>>rows;
    cout<<"Please enter the number of columns: "; cin>>cols;
    cout<<"Please enter the number of winning tokens: "; cin>>w;

    display_board(rows, cols);

}