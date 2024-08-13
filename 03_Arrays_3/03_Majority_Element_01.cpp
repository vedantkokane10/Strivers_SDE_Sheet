/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

There can exist only 1 element who appears more than n/2.
Because if n=8 then n/2 = 4, 5 > 4
so if a element appears 5 times then no other can appear 5 or even 4 times.
*/


int majorityElement(vector<int>& nums) {
    int count = 0;
    int element = -1;
    for(int i=0;i<nums.size();i++){
        if(count == 0){
            count = 1;
            element = nums[i];
        }
        else if(nums[i] == element){
            count++;
        }
        else{
            count--;
        }
    }

    return element;
}
