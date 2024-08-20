/*
Given a set of n jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with a job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
Deadline of the job is the time on or before which job needs to be completed to earn the profit.

Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Approach - 
Sort the jobs in descending order of profit.
Maintain a times array for mapping job ids to times at which they gets executed
iterate over jobs if the current job's dead is not mapped to any other id, then map it and update count and total sum profit.
else if the dead of the current job is marked with any other job id in times array then maintain pointer to dead-1
iterate until we found a empty times position or pointer is greater than 0
if we found a position then then map it and update count and total sum profit,
 else we need to skip that job as it cannot be mapped.

Ex- [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
sort -> [[3,1,40],[4,1,30],[1,4,20],[2,1,1]]
          1    2   3   4 
times -> -1 , -1, -1, -1

iterate - jobs[0] => dead = 1 , profit = 40, id = 3
since times[1] is not marked so mark it with id 3
          1    2   3   4 
times ->  3 , -1, -1, -1
cnt = 1
sum = 40

iterate - jobs[1] => dead = 1 , profit = 30, id = 4
since times[1] is  marked with id 3 and we don't have any previous index in times so we need to skip it.

iterate - jobs[2] => dead = 4 , profit = 20, id = 1
since times[2] is not marked so mark it with id 1
          1    2   3   4 
times ->  3 , -1, -1,  1
cnt = 2
sum = (40+20) => 60

iterate - jobs[3] => dead = 1 , profit = 1, id = 2
since times[1] is  marked with id 3 and we don't have any previous index in times so we need to skip it.

Final Answer => {2,60}

*/

const static bool cmp(Job &a, Job &b){
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    vector<int> times(n+1,-1);
    sort(arr,arr+n,cmp);
    int i = 0;
    int cnt = 0;
    int sum = 0;
    while(i < n){
        int id = arr[i].id;
        int dead = arr[i].dead;
        int profit = arr[i].profit;
        if(times[dead] == -1){
            times[dead] = id;
            cnt++;
            sum += profit;
        }
        else{
            int j = dead-1;
            while(j > 0 && times[j] != -1){
                j--;
            }
            if(j > 0){
                times[j] = id;   
                cnt++;
                sum += profit;
            }
        }
        
        i++;
    }
    return {cnt,sum};
} 
