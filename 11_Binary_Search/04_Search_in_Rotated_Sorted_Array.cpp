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

Approach - Find the privot element and apply binary search on the left half of pivot element and right half of the pivot element.
*/


int bs(vector<int>& nums, int target,int s,int e){
    while(s <= e){
        int mid = s + (e-s)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivot = -1;
    int n = nums.size()-1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i] > nums[i+1]){
            pivot = i;
        }
    }
    if(pivot == -1){
        return bs(nums,target,0,n);
    }
    if(bs(nums,target,0,pivot) != -1){
        return bs(nums,target,0,pivot);
    }
    return bs(nums,target,pivot+1,n);
}
