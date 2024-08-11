int maxSubArray(vector<int>& nums) {
    // Kadane Algorithm
    int sum = 0;
    int mx = INT_MIN;
    for(int i=0;i<nums.size();i++){
        sum = sum + nums[i];
        mx = max(mx,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return mx;
}
