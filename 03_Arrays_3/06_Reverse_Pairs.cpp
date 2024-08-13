/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Approach - Same as Inversion count but slight change,
Before merging two arrays, we iterate over the left array and maintain a pointer right array and
check if leftArray element is greater than twice the rightArray element and keep increment the pointer 
in a while loop and when the while loop terminated we add j to ans variable.
*/


int ans = 0;
void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> left,right;
    for(int i=low;i<=mid;i++){
        left.push_back(arr[i]);
    }
    for(int i=mid+1;i<=high;i++){
        right.push_back(arr[i]);
    }
    int i = 0;
    int j = 0;
    int k = low;
    
    for(int i=0;i<left.size();i++){
        while(j < right.size() && left[i] > right[j] * 2LL){
            j++;
        }
        ans +=  j;
    }


    i = 0;
    j = 0;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left.size()){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size()){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr,int low,int high){
    if(low >= high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    mergeSort(nums,0,n-1);

    return ans;
}
