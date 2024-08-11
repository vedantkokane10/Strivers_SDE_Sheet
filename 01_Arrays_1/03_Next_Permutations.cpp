/*
First find a element and store its index where ith element < i+1th element
if a element's index is found then search from behind for a greater element than element at the index.
Then simply swap them and reverse from index+1 to end and return.
[1,2,3]
2 < 3
THrerfore swap 2 , 3
[1,3,2] now reverse from index 1 to 2 ==> [1,2,,3]


If no element is found then simply reverse.
[3,2,1]
no element found where ith < i+1th
so simply reverse the array and return.
*/

void nextPermutation(vector<int>& nums) {
    int index = -1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[index] < nums[i]){
            swap(nums[index] , nums[i]);
            break;
        }
    }
    reverse(nums.begin()+index+1,nums.end());
}
