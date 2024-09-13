/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/


// for equal elements index
// left half -> even odd 
// right half -> odd even

/*
nums = [1,1,2,3,3,4,4,8,8]

1 1 2 3 3 4 4 8 8
0 1 2 3 4 5 6 7 8  <- Index  
E O   O E O E O E  <- Index position

Answer is at index 2 
1) so before answer index the equal elements are at position (Even, Odd)
2) so after answer index the  equal elements are at position (Odd, Even)

*/

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    int s = 0;
    int e = n - 1;
    while(s <= e){
        int mid = s + (e-s) / 2;
        if((mid > 0 && nums[mid] != nums[mid-1]) && (mid < n && nums[mid] != nums[mid+1])){
            return nums[mid];
        }
        else if(mid == 0 && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        else if(mid == n-1 && nums[mid] != nums[mid-1]){
            return nums[mid];
        }
        else if(mid % 2 == 0 && (nums[mid] == nums[mid+1])){
            s = mid+1;
        }
        else if(mid % 2 == 0 && (nums[mid] == nums[mid-1])){
            e = mid-1;
        }
        else if(mid % 2 != 0 && (nums[mid] == nums[mid-1])){
            s = mid+1;
        }
        else if(mid % 2 != 0 && (nums[mid] == nums[mid+1])){
            e = mid-1;
        }
    }
    return -1;
}
