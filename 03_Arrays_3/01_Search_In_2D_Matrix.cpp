/*
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.


Approach - We can flatten the Matrix into 1D array, of size (m*n)
and then we can apply binary search from 0 to (m*n)-1 when we calculate mid, we can use it to find the cell 
row = mid / no of columns
col = mid % no of columns

[ 1 2 3          
  4 5 6   =>  [1 2 3 4 5 6 7 8 9]
  7 8 9] 

  0 1 2  <- remainder for columns
  
  
3*3 -> 9 size

row - for row we are using mid / no of cols because each row has equal columns, 
so if mid = 4 then 4 / 3 -> 1 

col - for col we have to use modulo of mid % no of cols, carefully look we have 0 1 2 ... n colums so modulo to mid will give 
us the exact column.


Ex [1 2 3 4 5 6 7 8 9] target = 5
mid = (0+8) / 2;
mid = 4
row = mid / cols = (4/3)  -> 1
col = mid % cols = (4%3)  -> 1

matrix[row][col] = 5
returns true




*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int noOfRows = matrix.size();
    int noOfCols = matrix[0].size();

    int s = 0;
    int e = (noOfRows * noOfCols) - 1;
    while(s <= e){
        int mid = (s+e)/2;
        int row = mid / noOfCols;
        int col = mid % noOfCols;
        cout<<row<<" "<<col<<endl;
        if(matrix[row][col] > target){
            e = mid-1;
        }
        else if(matrix[row][col] < target){
            s = mid+1;
        }
        else{
            return true;
        }
    }

    return false;
}
