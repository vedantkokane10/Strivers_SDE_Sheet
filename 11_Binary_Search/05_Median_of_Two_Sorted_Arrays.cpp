/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size() + nums2.size();
    int mid = (0 + (n-1))/2;
    vector<int> temp = Medians(nums1,nums2,mid);
    if(n % 2 == 0){
        return (temp[0] + temp[1]) / 2.0;
    }

    return temp[0];
}

vector<int> Medians(vector<int>& nums1, vector<int>& nums2,int mid){
    int ans1 = 0;
    int ans2 = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int currentElement = 0;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] <= nums2[j]){
            currentElement = nums1[i];
            i++;
        }
        else{
            currentElement = nums2[j];
            j++;
        }
        if(k == mid){
            ans1 = currentElement;
        }
        if(k == mid+1){
            ans2 = currentElement;
        }
        k++;
    }

    while(i < nums1.size()){
        currentElement = nums1[i];
        i++;
        if(k == mid){
            ans1 = currentElement;
        }
        if(k == mid+1){
            ans2 = currentElement;
        }
        k++;
    }

    while(j < nums2.size()){
        currentElement = nums2[j];
        j++;
        if(k == mid){
            ans1 = currentElement;
        }
        if(k == mid+1){
            ans2 = currentElement;
        }
        k++;
    }

    return {ans1,ans2};
}
