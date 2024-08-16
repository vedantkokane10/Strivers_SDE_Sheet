/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int mx = 0;
    for(auto x:nums){
        if(x == 1){
            cnt++;
        }
        else{
            mx = max(mx,cnt);
            cnt = 0;
        }
    }
    mx = max(mx,cnt);

    return mx;
}
