/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.


Since numbers are from 1 to n and we have array of size n+1, 
we can iterate the array and assume the iterated element as index and 
mark the index of array to negative value by multiplying by -1.
Then if we found a element's index is marked with negative value  then we return that element.
*/


int findDuplicate(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int x = abs(nums[i]);
        if(nums[x] < 0){
            return abs(x);
        }
        if(nums[x] > 0){
            nums[x] = nums[x] * (-1);
        }
    }
    return -1;
}
