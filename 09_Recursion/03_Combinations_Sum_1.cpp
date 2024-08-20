/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

void helper(int ind,vector<int> sample,int sum,vector<int>& arr, int target,vector<vector<int>> &ans){
    if(sum == target){
        ans.push_back(sample);
        return;
    }

    if(ind >= arr.size() || sum > target){
        return;
    }


    // take
    sample.push_back(arr[ind]);
    helper(ind,sample,sum+arr[ind],arr,target,ans);
    sample.pop_back();


    // dont Take
        helper(ind+1,sample,sum,arr,target,ans);

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sample;
    helper(0,sample,0,candidates,target,ans);

    return ans;
}
