# Connect 4 Game
C++ Console Application Model of the Connect-4-Game 

Elapsed time: estimated 3 hours and 10 minutes in total
                (including manual testing, excluding this README)

main():
- rows, cols = number of rows and columns 
- tks = required tks to win
- line = the selected column in which a player drops a token
- board = vector matrix in order to keep the data across multiple functions

display_board(int n, int m, vector<vector<int>>& board):
- n and m for the limits of the grid
- displaying each players tokens by verifying the matrix 
    (if the matrix has a 1, it is a Red token, Yellow if it's 2)

move(bool red_playing, vector<vector<int>>& board, 
     int rows, int cols, int line, int tks):
- we are starting from the end of the matrix because in the real game, 
  all the tokens fall down at the bottom, so we need to check where is 
  the next available position on top (we know before hand if the pile is
  already full from line 92 when cheking for legal moves)
- from the last token placed, we check to the right of it until there are no
  more of the same token, then we go back and check to the left with the counter
  still going
- we reset the counter after each axis change as the game rules dictate it only
  needs a certain amount of tokens on one axis
- we do the same for vertical, primary diagonal and secondary diagonal
- if at any point there are at least consecutive tokens equal to the necessary
- we return false otherwise

Possible errors due to exciding the time limit:
    - there is no checking for the tokens need to win exceeding the grid's bounds 
