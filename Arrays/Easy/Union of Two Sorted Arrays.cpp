/*
Union of Two Sorted Arrays

Register for Mega Job-A-Thon For Experienced Professionals on 21st July | Apply to 15+ Companies

Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.

Example 1:
Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
 

Example 2:
Input: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
 

Example 3:
Input:
n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
Output: 1 2
Explanation: Distinct elements including 
both the arrays are: 1 2.

Your Task: 
You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays. 

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).

Constraints:
1 <= n, m <= 10^5
1 <= arr[i], brr[i] <= 10^6



*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0,j=0;
        vector<int> uni;
        while(i < n and j < m){
            if(arr1[i] <= arr2[j]){
                if(uni.size() == 0 or uni.back() != arr1[i]){
                    uni.push_back(arr1[i]);
                }
                i++;
            }
            else{
                if(uni.size() == 0 or uni.back() != arr2[j]){
                    uni.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        while(i < n){
            if(uni.back() != arr1[i]){
                uni.push_back(arr1[i]);
            }
            i++;
        }
        
        while(j < m){
            if(uni.back() != arr2[j]){
                uni.push_back(arr2[j]);
            }
            j++;
        }
        
        return uni;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){  
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends