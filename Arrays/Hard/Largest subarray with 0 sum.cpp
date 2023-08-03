/*
Largest subarray with 0 sum

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^5
-1000 <= A[i] <= 1000, for each valid i

Problem Link -> https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

//optimal approach
//Using prefixSum algorithm

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>& nums, int k)
    {   
        int sum = 0,maxl = 0;
        map <int,int> prefixSum;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == 0){
                maxl = i+1;
            }
            else{
                if(prefixSum.find(sum) != prefixSum.end()){
                    maxl = max(maxl,i-prefixSum[sum]);
                }
                else{
                    prefixSum[sum] = i;
                }
            }
        }
        return maxl;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends



