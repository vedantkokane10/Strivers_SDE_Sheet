/*
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.

Ex [3,1,2,,5,3] -> repeat = 3, missing = 4

Approach - 
First -
calculate sum of elements and sum from 1 to n
and subtract
= (3 + 1 + 2 + 5 + 3) - (1 + 2 + 3 + 4 + 5)
= 3 - 4 => -1
Assume x-y => 3-4
x - y = -1 


Second - calculate sum of square of elements and sum of square from 1 to n
and subtract
= (9 + 1 + 4 + 25 + 9) - (1 + 4 + 9 + 16 + 25)
= 9 - 16 => -7

x^2 - y^2 = -7
(x+y) (x-y) = -7
(x+y) = -7 / (x-y)

Therefore, x+y = -7/-1 => 7

No we have 2 equations
x-y = -1
x+y = 7
so we will add them 
2x = 6
x = 3

now if we put x value in x-y = -1
x-y = -1
x + 1 = y
3 + 1 = y
y = 4

Hence proved that x = 3, y = 4

 */



vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long sumOfElements = 0;
    long long sumOfN = (n * (n+1))/2;
    for(auto x:A){
        sumOfElements += x;
    } 
    
    // x-y = sum - sumN 
    long long diff1 = sumOfElements - sumOfN;
    
    long long sumOfElementsSquare = 0;
    long long sumOfNSquare = (n * (n + 1) * (2 * n + 1)) / 6;
    
    for(int i=0;i<n;i++){
        sumOfElementsSquare += ((long long)A[i] * (long long)A[i]);
    }
    // x^2 - y^2 = sum^2 - sumN^2
    // (x-y).(x+y) =  sum^2 - sumN^2
    long long diff2 = sumOfElementsSquare - sumOfNSquare;
    
    // x+y = (sum^2 - sumN^2) / (x-y)
    diff2 = diff2/diff1;
    
    // repating
    long long x = (diff1+diff2) / 2;
    
    // missing
    long long y = x - diff1;
    
    
    return {(int)x,(int)y};
}
