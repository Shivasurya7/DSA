/*
Left Rotate an Array by One

Problem Statement:
Given an array 'ARR'containing 'N' elements, rotate this
array left once and return it.

Rotating the array left by one means shifting all elements by
one place to the left and moving the first element to the last
position in the array.

Sample Input 1:
4
5 7 3 2 
Sample Output 1:
7 3 2 5
Explanation Of Sample Input 1:
Moved the first element to the last and rest all the elements to the left.

Sample Input 2:
5
4 0 3 2 5 
Sample Output 2:
0 3 2 5 4

Constraints :
1 <= N <= 10^5
1 <= ARR[i] <= 10^9

Time Limit: 1 sec
*/

//my solution

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& a, int k) {
    int n = a.size();
    int temp = a[0];
    for(int j = 0; j < n-1; j++){
        a[j] = a[j+1];
    }
    a[n-1] = temp;
    return a;
}
