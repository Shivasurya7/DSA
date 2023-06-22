/*
Find Nth root of M
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).

Example 1:
Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9

Example 2:
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input parameter and returns the nth root of m. If the root is not integer then returns -1.

Expected Time Complexity: O(n* log(m))
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 30
1 <= m <= 10^9
*/

int NthRoot(int n, int m)
{
   long long int l = 1,h = m,mid;
   
   while(l <= h){
	   
	   mid = (l+h)/2;
	   
	   if(pow(mid,n) == m){
		   return mid;
	   }
	   
	   else if(pow(mid,n) < m){
		   l = mid+1;
	   }
	   else{
		   h = mid-1;
	   }
   }
  return -1;
}

/*
method 2 -> for acurate square root with decimal_point -- tc - n*log2(m*10) sc - O(1)

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; // -> 0.0000001
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(pow(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    return low or high; // at this time both are almost equal.
}

*/