/*
Given a string s, find the length of the longest substring without repeating characters.

Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Approach - In this question, First I maintaned a map then i used the shrinkable sliding window with 2 pointers i=0, j=0  where j will be always moving  in the window first
I check if the current element is present in map or not. If present the i will be updated with max value between i and existing value of element + 1, We are taking max between current value and element's index
because for a new element if it is already present and its index is out of range of window then can affect the answe so we must select the increasing i.e max value of i so that it fits the window correctly . 
If not present do nothing. everytime for a element its index will be set to j in the map and the answer will be updated by taking max between current value of answer and (j-i+1). 
*/

int lengthOfLongestSubstring(string s) {
    int length = 0;
    int j = 0;
    int i = 0;
    unordered_map<int,int> mp;
    while(j < s.size()){
        if(mp.find(s[j]) != mp.end()){
            i = max(i,mp[s[j]]);
        }
        mp[s[j]] = j+1;
        length = max(length,j-i+1);
        j++;
    }
    return length;
}
