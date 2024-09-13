/*
Given an array of integers A of size N and an integer B.
The College library has N books. The ith book has A[i] number of pages.
You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.
A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.

Input 1:
A = [12, 34, 67, 90]
B = 2
Output 1:
113

There are two students. Books can be distributed in following fashion : 
1)  [12] and [34, 67, 90]
    Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
2)  [12, 34] and [67, 90]
    Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
3)  [12, 34, 67] and [90]
    Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
    Of the 3 cases, Option 3 has the minimum pages = 113.



We need to return minimum total pages which is maximum combined pages that we can allot.
In above example 113 is minimum total pages and maximum combined pages that we can allot.


Intuition - 
We can start from max element in the array and go further one by one incremented it. 
But there needs to be upper bound as well so can assume sum of the array.

low = max element of the array and high = sum of the array
so we can apply binary search and count the no of students getting books if it is less equal to B the move to left side as we want minimum
else move right side to find count no of students satisfying the condition. 
*/


int books(vector<int> &A, int B) {
    if(B > A.size()){
        return -1;
    }
    
    int low = A[0];
    int high = 0;
    for(auto x:A){
        low = max(low,x);
        high += x;
    }
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = countNoOfStudentsGotBooks(A,mid);
        if(cnt <= B){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    
    return ans;
}

int countNoOfStudentsGotBooks(vector<int> &A,int maxPagesAllowed){
    int cnt = 1;
    int currentPagesCount = A[0];
    for(int i=1;i<A.size();i++){
        if(currentPagesCount + A[i] <= maxPagesAllowed){
            currentPagesCount = currentPagesCount + A[i];
        }
        else{
            cnt++;
            currentPagesCount = A[i];
        }
    }
    
    return cnt;
}
