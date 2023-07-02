/*
Reverse a String - using recursion

You are given a string s. You need to reverse the string.

Example 1:
Input:
s = Geeks
Output: skeeG

Example 2:
Input:
s = for
Output: rof

Your Task:
You only need to complete the function reverseWord() that takes s as parameter and returns the reversed string.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 <= |s| <= 10000
*/

//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str,int n = 0){
    if(str.length()==0 or str.length() == 1){
        return str;
    }
    char t = str[n];
    str[n] = str[(str.length()-n)-1];
    str[(str.length()-n)-1] = t;
    if(n == (str.length()/2)-1){
        return str;
    }
    return reverseWord(str,n+1);
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends