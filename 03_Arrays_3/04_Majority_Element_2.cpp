/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Only 2 elements can be there in a array with frequency greater than n/3.
*/

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    int e1 = 0, e2 = 0;
    int c1 = 0, c2 = 0;
    for(auto x:nums){
        if(x == e1){
            c1++;
        }
        else if(x == e2){
            c2++;
        }
        else if(c1 == 0){
            e1 = x;
            c1 = 1;
        }
        else if(c2 == 0){
            e2 = x;
            c2 = 1;
        }
        else{
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for(auto x:nums){
        if(x == e1){
            c1++;
        }
        else if(x == e2){
            c2++;
        }
    }
    if(c1 > (n/3)){
        ans.push_back(e1);
    }
    if(c2 > (n/3)){
        ans.push_back(e2);
    }
    return ans;
}
