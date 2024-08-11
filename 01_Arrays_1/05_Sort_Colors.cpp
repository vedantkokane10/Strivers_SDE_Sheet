
/*
Assume from 0 to low -> 0s
Assum from low+1 to mid -> 1s
Assusm from mid+1 to high-1 -> unsorted 0s,1s,2s
Assume from high+1 to n-1 -> 2s

Now move from mid since low = mid (initally)
if mid element is 0 swap it with low and increment low and mid
if mid element is 1, simply increment mid
if mid element is 2, swap it with high and decrement high , dont change mid
*/
void sortColors(vector<int>& nums) {
    int mid = 0;
    int low = 0;
    int high = nums.size() - 1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[high],nums[mid]);
            high--;
        }
        else{
            mid++;
        }
    }
    
}
