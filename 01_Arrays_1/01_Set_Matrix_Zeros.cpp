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
