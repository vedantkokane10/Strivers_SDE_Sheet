/*
Given two equally sized 1-D arrays A, B containing N integers each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum C valid sum combinations from all the possible sum combinations.

Example Input
Input 1:
 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


Example Output
Output 1:
 [7, 6]
Output 2:
 [10, 9, 9, 8]
*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<int,pair<int,int>>> q1;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    set<pair<int,int>> s1;
    int x = A.size()-1;
    int y = B.size()-1;
    int sum = A[x] + B[y];
    q1.push({sum,{x,y}});
    s1.insert({x,y});
    vector<int> ans;
    while(C--){
        x = q1.top().second.first;
        y = q1.top().second.second;
        sum = q1.top().first;
        ans.push_back(sum);
        q1.pop();
        if(x-1 > 0 && s1.find({x-1,y}) == s1.end()){
            q1.push({A[x-1]+B[y] , {x-1,y}});
            s1.insert({x-1,y});
        }
        if(y-1 > 0 && s1.find({x,y-1}) == s1.end()){
            q1.push({A[x]+B[y-1] , {x,y-1}});
            s1.insert({x,y-1});
        }
        
    }
    return ans;
}

