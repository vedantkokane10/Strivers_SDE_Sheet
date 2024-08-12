/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).


  0 1 2         0 1 2         0 1 2
0 1 2 3       0 1 4 7      0  7 4 1
1 4 5 6   =>  1 2 5 8  =>  1  8 5 2
2 7 8 9       2 3 6 9      2  9 6 3

             Transpose     Rows reversed

Transpose -> rows are swapped with columns
Therefore, swap matrix[i][j] with matrix[j][i], do this for upper triangle (above diagonal elements) only as applying the same to lower trianlge will not change anything.

Reverse rows and thats it
*/





void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i != j){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
