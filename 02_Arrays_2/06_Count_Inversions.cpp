/*
Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 


We know  that in merge sort we have 2 sorted arrays before merging,
so if we have 2 arrays [2,4] and [1,3,5]

while merging 2 arrays, using i,j pointers 
if leftArray[i] > rightArray[j]
then all the elements from to the right of ith element in the leftArray are also greater than rightArray[j], so that pairs also count
so we update the answer variable with the length of leftArray ((mid - low + 1) - left).

For instance for 2 in leftArray and j=0 which will point to 1 in rightArray, so all elements to right of 2 can form pair with 1,
hence 4 in leftArray can also form a pair with 1. 
Therefore ans += 2 (2,4)

Similarly for 4 in leftArray when j=1 which will point to 3 in rightArray, all elements right to 4 can also form pair with 3,
since in this case 4 is last element in leftArray only it can form a pair with 3.
*/

long long ans = 0;

void merge(long long arr[],long long low,long long mid,long long high){
	vector<long long > leftArray,rightArray;
	for(int i=low;i<=mid;i++){
		leftArray.push_back(arr[i]);
	}
	for(int i=mid+1;i<=high;i++){
		rightArray.push_back(arr[i]);
	}
	long long  left = 0;
	long long  right = 0;
	long long  k = low;
	while(left < leftArray.size() && right < rightArray.size()){
		if(leftArray[left] <= rightArray[right]){
			arr[k] = leftArray[left];
			left++;
		}
		else{
		  ans += (mid - low + 1) - left;
			arr[k] = rightArray[right];
			right++;
		}
		k++;
	}
	while(left < leftArray.size()){
		arr[k] = leftArray[left];
		left++;
		k++;
	}
	while(right < rightArray.size()){
		arr[k] = rightArray[right];
		right++;
		k++;
	}
}

void mergeSort(long long arr[],long long low,long long high){
	if(low >= high){
		return;
	}
	int mid = (low+high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

long long int inversionCount(long long arr[], int n) {
    // Your Code Here
    
    mergeSort(arr,0,n-1);
    return ans;
}
