/*
The upper bound in a sorted array is the index of the first value that is greater than the target value. 

Example:
Input : ‘arr’ = {2,4,6,7} and ‘x’ = 5,
Output: 2

Sample Input 1:
5 7
1 4 7 8 10
Sample Output 1:
3   

Sample Input 2:
5 10
1 2 5 6 10   
Sample Output 2:
5

Sample Input 3:
7 5
1 5 5 7 7 9 10
Sample Output 3:
3
*/


int upperBound(vector<int> &arr, int x, int n){
	int s = 0;
	int e = n-1;
	int ans = n;
	while(s <= e){
		int mid = s + (e-s)/2;
		if(arr[mid] > x){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ans;
}
