/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
*/


// Memorization
int helper(int m,int n,vector<vector<int>> &dp){
    if(m < 0 || n < 0){
        return 0;
    }
    if(m == 0 && n == 0){
        return 1;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    int right = helper(m-1,n,dp);
    int down = helper(m,n-1,dp);

    return dp[m][n] = right + down;
}

// tabulated
int uniquePaths(int m, int n) {
    if(m == 1 && n == 1){
        return 1;
    }
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
            else{
                int left = 0, up = 0;
                if(i > 0){
                    left = dp[i-1][j];
                }
                if(j > 0){
                    up = dp[i][j-1];
                }
                dp[i][j] = left + up;
            }
        }
    }
    return dp[m-1][n-1];
}
