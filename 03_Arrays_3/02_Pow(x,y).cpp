/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000


even power - make x double and make n half
odd power - update answer with (answer * x) and decrement n

Ex - x = 2.0 , n = 10
ans = 1.0

n = 10  even
x = x * x => 4.0
n = n / 2 => 5

n = 5 odd
ans = ans * x => 4.0
n = n - 1 => 4

n = 4  even
x = x * x => 16.0
n = n / 2 => 2

n = 2  even
x = x * x => 256.0
n = n / 2 => 1

n = 1 odd
ans = ans * x => 4.0 * 256.0 => 1024.0
n = n - 1 => 0

Answer = 1024.0
*/

double myPow(double x, int n) {
    double ans = 1.0;
    long long num = abs(n);
    while(num > 0){
        if(num & 1 == 0){
            x = x * x;
            num = (num/2);
        }
        else{
            ans = ans * x;
            num--;
        }
    }
    if(n < 0){
        return 1.0 / (ans);
    }
    return ans;
}
