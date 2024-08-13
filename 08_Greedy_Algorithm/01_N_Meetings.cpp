/*
Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

Approach -
Sort meetings based on start time.
Set current time to first meeting's end time and then iterate see if current time is less than iterated meeting's start time
if it is less then increment counter and set current time to iterated meeting's end time.
*/


const static bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int,int>> meetings(n);
    for(int i=0;i<n;i++){
        meetings[i] = {start[i],end[i]};
    }
    sort(meetings.begin(),meetings.end(),cmp);
    int cnt = 1;
    int currentEndTime = meetings[0].second;
    for(int i=1;i<n;i++){
        //cout<<meetings[i].first<< " "<< meetings[i].second<<endl;
        if(currentEndTime < meetings[i].first){
            cnt++;
            currentEndTime = meetings[i].second;
        }
    }
    return cnt;
}
