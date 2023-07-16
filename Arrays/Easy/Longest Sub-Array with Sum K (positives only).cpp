/*
Longest Sub-Array with Sum K (positives only)

Problem Statement:
You are given an array 'A' of size 'N' and an integer 'K'. You
need to print the length of the longest subarray of array 'A'
whose sum 'K'.

Sample Input 1:
7 3
1 2 3 1 1 1 1
Sample Output 1 :
3

Explanation Of Sample Input 1:
Input: ‘N’ = 7 ‘K’ = 3
‘A’ = [1, 2, 3, 1, 1, 1, 1]
Output: 3
Explanation: Subarrays whose sum = ‘3’ are:
[1, 2], [3], [1, 1, 1], [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.

Sample Input 2:
4 2
1 2 1 3
Sample Output 2:
1

Sample Input 3:
5 2
2 2 4 1 2 
Sample Output 3:
1

Constraints:
1 <= N, K <= 10^3
0 <= A[i] <= 10^9
Time Limit: 1-sec
*/

//my approach (optimal approach)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = 0,max1 = 0,j = 0;
    for(int  i = 0; i < a.size(); i++){
        sum += a[i];
        while(sum > k){
            sum -= a[j];
            j++;
        }
        if(sum == k){
            max1 = max(max1,(i-j)+1);
        }
    }
    return max1;
}

