/*
Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


Examples :
Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].

Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].


Approach -
Maintain min-heap of pair data structure and a array of n elements which will have index of the subarrays. indexOfArray

Iterate and store first elements of each subarray along with its arrayNumber (its position in main array) in the heap.

Maintain a answer array and empty the heap get top element and the arrayNumber put the element in ans
and increment the index in the indexOfArray and store new element along with array number in heap.
Repeat this until heap is not empty.

Return answer array at end.

*/


vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    vector<int> indexOfArray(arr.size(),0);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],i});
    }
    
    vector<int> ans;
    while(!pq.empty()){
        int element = pq.top().first;
        int arrayNumber = pq.top().second;
        pq.pop();
        ans.push_back(element);
        indexOfArray[arrayNumber]++;
        if(indexOfArray[arrayNumber] >=  arr[arrayNumber].size()){
            continue;
        }
        pq.push({arr[arrayNumber][indexOfArray[arrayNumber]],arrayNumber});
    }
    return ans;
}
