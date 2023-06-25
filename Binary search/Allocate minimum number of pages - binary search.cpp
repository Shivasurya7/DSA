/*
Allocate minimum number of pages

Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Example 1:
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.

Example 2:
Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}
Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105
*/

class Solution 
{
    public:
    int isPossible(int arr[],int n,int m,int s){
        int sum = 0,c=0;
        for(int  i = 0; i < s; i++){
            if(arr[i] > m){
                return 0;
            }
            if(sum + arr[i] > m){
                c++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
    
        if(c < n){
            return 1;
        }
        else{
            return 0;
        }
    }
    int findPages(int arr[], int n, int m) 
    {
        if (m > n) {
        return -1;
        }
        int l = arr[0], h = 0,mid,ans;
        for(int  i = 0; i < n; i++){
    
            h += arr[i];
            if(l > arr[i]){
                l = arr[i];
            }
        }
        
        while(l <= h){
            mid = (l+h)/2;
            if(isPossible(arr,m,mid,n)){
                h = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};