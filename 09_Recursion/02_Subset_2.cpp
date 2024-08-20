/*
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
*/

void helper(int ind,vector<int> sample,vector<int>& nums,vector<vector<int>> &ans){
    if(ind >= nums.size()){
        ans.push_back(sample);
        return;
    }

    // take
    sample.push_back(nums[ind]);
    helper(ind+1,sample,nums,ans);
    sample.pop_back();

    // dont take
    // skip the elements which are identical
    while(ind < nums.size()-1 && nums[ind] == nums[ind+1]){
        ind++;
    }
    helper(ind+1,sample,nums,ans);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> sample;
    sort(nums.begin(), nums.end());
    helper(0,sample,nums,ans);
    return ans;
}
