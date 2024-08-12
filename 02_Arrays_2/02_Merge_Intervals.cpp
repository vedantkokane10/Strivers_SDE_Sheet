/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and
return an array of the non-overlapping intervals that cover all the intervals in the input.

Approach - sort the given array and push the 0th element in answer array iterate over the array from 1 to n
get the last element of answer array compare it with the current iterated element, if current iterated element is inbetween the last element in array
then update the last element of answer array else push the current iterated element to the answer array.
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        int a = ans.back()[0];
        int b = ans.back()[1];
        if(intervals[i][0] >= a && intervals[i][0] <= b){
            a = min(a,intervals[i][0]);
            b = max(b,intervals[i][1]);
            ans.back()[0] = a;
            ans.back()[1] = b;
        }
        else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
