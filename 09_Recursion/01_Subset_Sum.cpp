/*
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

Example :
Input:
n = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
*/

void helper(int ind,int sum,vector<int> arr,vector<int> &ans){
    if(ind == arr.size()){
        ans.push_back(sum);
        return;
    }

    // take
    helper(ind+1,sum+arr[ind],arr,ans);
    
    // dont take
    helper(ind+1,sum,arr,ans);
    
    
}
vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    helper(0,0,arr,ans);
    
    return ans;
}
