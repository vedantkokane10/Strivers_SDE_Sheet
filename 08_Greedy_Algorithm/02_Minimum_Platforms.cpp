/*
Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. 
Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train.
In such cases, we need different platforms.

Input: n = 6, arr[] = {0900, 0940, 0950, 1100, 1500, 1800}, 
            dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: There are three trains during the time 0940 to 1200. So we need minimum 3 platforms.


Approach - first sort the arrays don't worry about the pairs,
keep 2 pointers, 1 pointing at arrival and second at departure ,
iterate if arr[i] <= departure[j] that means we need a new platform
else we don't need a new platform, so increment/decrement counters and update max variable.

*/


int findPlatform(int arr[], int dep[], int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	int i = 0;
	int j = 0;
	int platformsCount = 0;
	int mx = 0;
	while(i < n){
	    if(arr[i] <= dep[j]){
	        platformsCount++;
	        mx = max(mx,platformsCount);
	        i++;
	    }
	    else{
	        platformsCount--;
	        j++;
	    }
	}
	return mx;
}
