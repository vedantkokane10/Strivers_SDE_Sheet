/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Approach - Maintain 2 pointers i,j keep i at last element of nums1 and j at the first element of nums2 
iterate in a while loop and keep decrementing i and increment j only if nums1[i] > nums2[j] is satisfied and if it is
satisfied then swap nums1[i] nums2[j].

After the while loop ends replace the 0s in nums1 with elements of nums2.

At last sort nums1 first from 0 to m and then from m to m+n indexes.

*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = 0;
    while(i >= 0 && j < n){
        if(nums1[i] > nums2[j]){
            int temp = nums1[i];
            nums1[i] = nums2[j];
            nums2[j] = temp;
            j++;
        }
        i--;
    }
    j = 0;
    for(int i=m;i<m+n;i++){
        nums1[i] = nums2[j];
        j++;
    }
    sort(nums1.begin(),nums1.begin() + m);
    sort(nums1.begin()+m,nums1.end());


    // TC - O(min(m,n)) + O(mlogm) + O(nlogn)
    // SC - O (1)
}
