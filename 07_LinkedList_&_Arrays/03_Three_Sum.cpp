/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int target = 0;
    vector<vector<int>>  ans;
    for(int i=0;i<n;i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j < k){
            long long sum = 0;
            sum += nums[i];
            sum += nums[j];
            sum += nums[k];
            if(sum > target){
                k--;
            }
            else if(sum < target){
                j++;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]){
                    j++;
                }
                while(k > j && nums[k] == nums[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}
