/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Input: board = 
[["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]

Output:

[["5","3","4","6","7","8","9","1","2"],
 ["6","7","2","1","9","5","3","4","8"],
 ["1","9","8","3","4","2","5","6","7"],
 ["8","5","9","7","6","1","4","2","3"],
 ["4","2","6","8","5","3","7","9","1"],
 ["7","1","3","9","2","4","8","5","6"],
 ["9","6","1","5","3","7","2","8","4"],
 ["2","8","7","4","1","9","6","3","5"],
 ["3","4","5","2","8","6","1","7","9"]]

*/



bool isValid(int row,int col,char character,vector<vector<char>>& board){
    for(int i=0;i<9;i++){ 
        // to check in row
        if(board[i][col] == character){
            return 0;
        }
        // to check in col
        if(board[row][i] == character){
            return 0;
        }

        // to check in 3x3 grid
        if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == character){
            return 0;
        }
    }

    return 1;
}

bool helper(int row,int col,vector<vector<char>>& board){
    // base case - if last row is reached that means we got answer
    if(row == 9){
        return 1;
    }

    // if last column is reached then we need to move on the next row starting from first column
    if(col == 9){
        return helper(row+1,0,board);
    }

    // if the cell already has a character then no need to assign anything simply move to next column
    if(board[row][col] != '.'){
        return helper(row,col+1,board) ;
    }

    for(char c='1';c<='9';c++){
        if(isValid(row,col,c,board) == 1){
            board[row][col] = c;
            if(helper(row,col+1,board) == 1){
                return 1;
            }

            // backtrack and undo assgining character
            board[row][col] = '.';
        }
        
    }
    return 0;
}
void solveSudoku(vector<vector<char>>& board) {
    helper(0,0,board);
}
