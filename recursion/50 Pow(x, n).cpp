/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= xn <= 10^4
*/

// recursive approach (beats 100%)
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n<0){
            n = abs(n);
            if(n%2){
                return 1/(x*myPow(x,n-1));
            }
            else{
                return 1/myPow(x*x,n/2);
            }
        }
        else{
            if(n%2){
                return x*myPow(x,n-1);
              
            }
            else{
                return myPow(x*x,n/2);
            }
        }
    }
};

//normal approacch

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long m = abs(n);
        while(m){
            if(m%2){
                ans = ans*x;
                m--;
            }
            else{
                x = x*x;
                m /= 2;
            }
        }
        if(n < 0){
            return 1/ans;
        }
        return ans;
    }
};