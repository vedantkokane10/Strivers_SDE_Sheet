/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Simulation - 

height =   [0,1,0,2,1,0,1,3,2,1,2,1]
leftMax =  [0,1,1,2,2,2,2,3,3,3,3,3]
rightMax = [3,3,3,3,3,3,3,3,2,2,2,1]

ans += minimum between(leftMax[i],rightMax[i]) - height[i]

Idea is simple the water can be hold by blocks which are minimum in height,
The amount of water will the difference between current height of block and minimum length of height of blocks.
*/

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n);
    vector<int> rightMax(n);
    int left = height[0];
    for(int i=0;i<n;i++){
        left = max(left,height[i]);
        leftMax[i] = left;
    }

    int right = height[n-1];
    for(int i=n-1;i>=0;i--){
        right = max(right,height[i]);
        rightMax[i] = right;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans +=  min(leftMax[i],rightMax[i]) - height[i] ;
    }

    return ans;
}
