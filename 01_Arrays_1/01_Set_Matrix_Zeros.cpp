/*
Assume that the first row and column are seperate row and column which will be marked if any 0 is found in ith row or jth column.
Then just iterate over the matrix again if first row or column of the current element is 0 then mark the current cell as 0.
We need to keep two boolean variable rowZero and colZero to check for 0th row and 0th column, if either of both is set then update the first row and column with 0s.
*/

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool rowZero = 0;
    bool colZero = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 || j == 0){
                if(matrix[i][j] == 0){
                    if(i == 0){
                        rowZero = 1;
                    }
                    if(j == 0){
                        colZero = 1;
                    }
                }
            }
            else{
                if(i > 0 && j > 0 &&  matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    // first column
    if(colZero == 1){
        for(int i=0;i<m;i++){
            matrix[i][0] = 0;
        }
    }
    // first row
    if(rowZero == 1){
        for(int i=0;i<n;i++){
            matrix[0][i] = 0;
        }
    }
}
