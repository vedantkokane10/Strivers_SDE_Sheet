/*
input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


*/

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int j = 1;
    while(j < nums.size()){
        if(nums[j] != nums[i]){
            i++;
            swap(nums[i],nums[j]);
        }
        j++;
    }
    return i+1;
}
