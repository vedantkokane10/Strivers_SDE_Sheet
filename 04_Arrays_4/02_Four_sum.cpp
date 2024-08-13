vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>>  ans;
    for(int i=0;i<n;i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }
            
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = 0;
                sum += nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum > target){
                    l--;
                }
                else if(sum < target){
                    k++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(l > k && nums[l] == nums[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}
