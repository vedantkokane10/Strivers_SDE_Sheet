/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

Approach - 
First find out the range by finding minimum and maximum elements from array.
Then apply Binary search on range and find mid once mid is found we need to find elements smaller or equal to the mid
for we can apply upperbound for the mid on every row, if the count is less than equal to (m*n)/2 then move to second half of mid else move to first half.
*/

int elementsSmallerThanEqualToMid(vector<vector<int>> &matrix,int mid){
    int n = matrix.size();
    int m = matrix.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
    }
    
    return cnt;
}

int median(vector<vector<int>> &matrix, int R, int C){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0;i<n;i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][m-1]);
    }
    
    while(low <= high){
        int mid = (low + high) / 2;
        int count = elementsSmallerThanEqualToMid(matrix,mid);
        if(count <= ((n*m)/2)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
