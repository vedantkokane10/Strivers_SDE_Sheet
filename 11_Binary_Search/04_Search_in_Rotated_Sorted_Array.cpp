/*
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

*/


int search(vector<int>& nums, int target) {
    int mn = INT_MAX;
    int low = 0;
    int high = nums.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else if(nums[mid] <= nums[high]){
            if(nums[mid] <= target && target <= nums[high]){
                low = mid+1;  
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
