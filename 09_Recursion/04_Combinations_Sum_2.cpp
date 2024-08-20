/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

void helper(int ind,int target,vector<int>& arr,vector<int> sample,vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(sample);
        return;
    }
    
    if(ind >= arr.size() || target < 0){
        return;
    }

    // take
    if(arr[ind] <= target){
        sample.push_back(arr[ind]);
        helper(ind+1,target-arr[ind],arr,sample,ans);
        sample.pop_back();
    }
    
    // skipping elements that are identical
    while(ind < arr.size()-1 && arr[ind] == arr[ind+1]){
        ind++;
    }

    // dont take
    helper(ind+1,target,arr,sample,ans);

    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> sample;
    helper(0,target,candidates,sample,ans);
    return ans;
}
