/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is
blocked and rat cannot move to it while value 1 at a cell in the matrix represents 
that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, 
return an empty list. The driver will output "-1" automatically.

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, 
when printed in sorted order we get DDRDRR DRDDRR.
*/


void helper(int row,int col,vector<vector<int>> &mat,vector<string> &ans ,string sample,vector<vector<bool>> &vis){
    int m = mat.size();
    int n = mat[0].size();
    if(row >= m || col >= n){
        return;
    }
    if(row == m-1 && col == n-1){
        ans.push_back(sample);
        return;
    }
    
    
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    char directions[4] = {'L','U','R','D'};
    
    for(int i=0;i<4;i++){
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        char currentDirection = directions[i];
        if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
            if(mat[nrow][ncol] == 1 &&  !vis[nrow][ncol]){
                vis[row][col] = true;
                sample.push_back(currentDirection);
                helper(nrow,ncol,mat,ans,sample,vis);
                sample.pop_back();
                vis[row][col] = false;
            }
           
        }
    }
    
    
}

vector<string> findPath(vector<vector<int>> &mat) {
    // Your code goes here
    if(mat[0][0] == 0){
        return {"-1"};
    }
    int m = mat.size();
    int n = mat[0].size();
    vector<string> ans;
    vector<vector<bool>> vis(m, vector<bool>(mat[0].size(), false));
    helper(0,0,mat,ans,"",vis);
    return ans;
}
