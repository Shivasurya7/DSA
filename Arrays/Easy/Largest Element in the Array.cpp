/*
Largest Element in the Array
Problem Statement
Given an array 'ARR' of size 'N' find the largest
element in the array.

Sample Input 1:
6
4 7 8 6 7 6 
Sample Output 1:
8
Explanation Of Sample Input 1:
The answer is 8.
From {4 7 8 6 7 6}, 8 is the largest element.

Sample Input 2:
8
5 9 3 4 8 4 3 10 
Sample Output 2:
10

Constraints :
1 <= 'N' <= 10^5
1 <= 'ARR[i]' <= 10^9

Time Limit: 1 sec
*/

#include <bits/stdc++.h> 
int largestElement(vector<int> &a, int n) {
    int max1 = a[0];
    for(int i = 0; i < n; i++){
        if(max1 < a[i]){
            max1 = a[i];
        }
    }
    return max1;
}

