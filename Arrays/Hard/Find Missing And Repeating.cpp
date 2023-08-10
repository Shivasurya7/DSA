/*
Find Missing And Repeating

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Example 2:
Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 10^5
1 ≤ Arr[i] ≤ N

Problem Link -> https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
*/

//optimal approach 
//using maths concept (by sloving equation)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int k) {
        long long n = k; // size of the array
         // Find Sum of n number and Sum of n^2 numbers:
        long long sumN = (n*(n+1))/2,sumNs = (n*(n+1)*(2*n+1)) / 6;
        // Calculate Sum of the array and Sum of the squar of the array:
        long long sum = 0,sumSr = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            sumSr += (long)arr[i] * (long)arr[i];
        }
        long long nDif,sDif;
        nDif = sum - sumN; // X-Y:
        sDif = sumSr - sumNs; // X^2-Y^2:
        sDif = sDif/nDif; //Find X+Y = (X^2-Y^2)/(X-Y):
        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = nDif and X+Y = sDif:
        long long  x = (nDif + sDif)/2;
        long long y = x - nDif;
        return {(int)x,(int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends