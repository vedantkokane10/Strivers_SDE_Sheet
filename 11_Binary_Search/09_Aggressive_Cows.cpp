/*
You are given an array consisting of n integers which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to
k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:
Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.

1    2  4    8   9 
c1      c2   c3         At a distance of atleast 3 between each stalls.

Example 2:
Input:
n=5 
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.
*/

bool isPossible(vector<int> &stalls,int minDistanceAllowed,int noOfCows){
    // Allocating first cow at index 0
    int cowsAlloted = 1;
    int lastPlacedLocation = stalls[0];
    
    
    for(int i=1;i<stalls.size();i++){
        if((stalls[i] - lastPlacedLocation) >= minDistanceAllowed){
            cowsAlloted++;
            lastPlacedLocation = stalls[i];
        }

    }
    if(noOfCows <= cowsAlloted){
        return 1;
    }
    return 0;
}

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = -1;
    while(low <= high){
        int mid = (low+high) / 2;
        if(isPossible(stalls,mid,k) == 1){
            ans = max(ans,mid);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
