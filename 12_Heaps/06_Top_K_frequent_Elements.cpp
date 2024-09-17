/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Example 2:
Input: nums = [1], k = 1
Output: [1]

*/


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(auto x:nums){
        mp[x]++;
    }

    priority_queue<pair<int,int>> q1;

    for(auto x:mp){
        q1.push({x.second,x.first});
    }

    vector<int> ans;
    while(k > 0){
        ans.push_back(q1.top().second);
        k--;
        q1.pop();
    } 

    return ans;
}
