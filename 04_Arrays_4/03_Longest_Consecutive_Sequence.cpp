/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.


Approach - 
First put each element in a set,
Then iterate over the array if the current iterated element is first (it does not have any previous element)
then run while loop until we find next consecutive elements calculate length, update max length.
At end return max length.
*/

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s1;
    for(auto x:nums){
        s1.insert(x);
    }
    int length = 0;
    for(auto x:nums){
        int cnt = 1;
        if(s1.find(x-1) == s1.end()){
            int element = x+1;
            while(s1.find(element) != s1.end()){
                cnt++;
                element++;
            }
            length = max(length,cnt);
        }
    }
    return length;
}
