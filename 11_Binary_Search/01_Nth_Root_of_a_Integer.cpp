/*
You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.

Sample Input 1:
3 27
Sample Output 1:
3
Explanation For Sample Input 1:
3rd Root of 27 is 3, as (3)^3 equals 27.

Sample Input 2:
4 69
Sample Output 2:
-1
Explanation For Sample Input 2:
4th Root of 69 is not an integer, hence -1.

*/


// 2 ==> greater than mid
// 1 ==> equal to mid
// 0 ==> less than mid

int helper(int mid,int pow,int m){
  long long ans = 1;
  for(int i=1;i<=pow;i++){
    ans = ans * mid;
    if(ans > m){
      return 2;
    }
  }
  if(ans == m){
    return 1;
  }
  return 0;
}

int NthRoot(int n, int m) {
  int s = 1;
  int e = m;
  while(s <= e){
    int mid = (s+e)/2;
    int tempAnswer = helper(mid,n,m);
    if(tempAnswer == 1){
      return mid;
    }
    else if(tempAnswer == 2){
      e = mid-1;
    }
    else{
      s = mid+1;
    }
  }
  return -1;
}
