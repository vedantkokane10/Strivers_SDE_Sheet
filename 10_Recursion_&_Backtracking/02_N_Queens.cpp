/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
  
Input: n = 4
Output: . Q . .
        . . . Q
        Q . . .
        . . Q .

        . . Q .
        Q . . .
        . . . Q
        . Q . .
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


Approach - We need to visit each coloumn and check for every possible outcome by iterating the row
so when we are at any cell we need check for  -
                                                  \
                                                  - (i,j)
                                                  /
same row , 
upper left diagonal
and lower left diagonal 
we need to check for left side only and not for right side since it will be generated in the future.
*/

vector<vector<string>> ans;
int size;
bool isSafe(int row, int col, vector<string> &board) {
    // same row
    for(int i=0;i<col;i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // We shoudl check for only left side as right side will be generated in the future

    // upper diagonal elements
    for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i=row+1,j=col-1;i<board.size() && j>=0; i++,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void helper2(int col, vector<string> &board) {
    if (col == size) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < board.size(); row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            helper2(col + 1, board);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    size = n;
    vector<string> board(size);
    string s(size,'.');
    for(int i=0;i<size;i++){
        board[i] = s;
    }
    helper2(0,board);
    return ans;
}
