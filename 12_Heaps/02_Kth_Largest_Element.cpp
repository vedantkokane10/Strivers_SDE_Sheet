/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/


int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> q1;
    for(auto x:nums){
        q1.push(x);
    }

    while(k-1 > 0){
        q1.pop();
        k--;
    }

    return q1.top();
}
