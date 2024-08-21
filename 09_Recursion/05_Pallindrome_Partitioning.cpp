/*

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]





In my approach we can just check at each index that the left part i.e from [ind,i] if it is pallindrome then make a parition.
If ind == str.size() then it is one of the answer and store it in ans vector. In recursion we will consider a index starting from ind and will explore every possible outcome 
i.e we will run a loop from current ind to str.size() and if left part i.e  [ind,i] if pallindrome then make another recursion. 
When function makes return call we backtrack and undo everything inside the for loop.
*/

bool pallindrome(string str,int s,int e){
    while(s < e){
        if(str[s] != str[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
void helper(int ind,vector<string> sample,vector<vector<string>> &ans,string s){
    if(ind == s.size()){
        ans.push_back(sample);
        return;
    }

    for(int i=ind;i<s.size();i++){
        if(pallindrome(s,ind,i) == 1){
            sample.push_back(s.substr(ind,i-ind+1));
            helper(i+1,sample,ans,s);
            sample.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> sample;
    helper(0,sample,ans,s);
    return ans;
}
