/*
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.


Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6

 Output -  4

 Same problem as previous just XOR is done.
*/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    mp[0] = 1;
    int cnt = 0;
    int xor1 = 0;
    for(int i=0;i<A.size();i++){
        xor1 = xor1 ^ A[i];
        int x = xor1 ^ B;
        if(mp.find(x) != mp.end()){
            cnt += mp[x];
        }
        mp[xor1]++;
    }
    return cnt;
}
