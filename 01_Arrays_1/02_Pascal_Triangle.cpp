/*
Each row is combination of nCr where n is the ith row and r moves from 0 to i.
Ex -> row = 3 -> 3C0 , 3C1 , 3C2 , 3C3 
                  1     3     3     1

Apply this logic!
*/


vector<int> ncr(int row){
    vector<int> result;
    int ans = 1;
    result.push_back(ans);
    for(int i=0;i<row;i++){
        ans = ans * (row - i);
        ans = ans / (i+1);
        result.push_back(ans);
    }
    return result;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++){
        vector<int> result = ncr(i);
        ans.push_back(result);
    }
    return ans;
}
