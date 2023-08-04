/*
Subarrays with XOR ‘K’

Problem Statement
Given an array 'A' consisting of 'N' integers
and an integer 'B', find the number of
subarrays of array 'A' whose bitwise XOR(^)
of all elements is equal to 'B'.

Sample Input 1:
4 2
1 2 3 2
Sample Output 1 :
3
Explanation Of Sample Input 1:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]
Output: 3
Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].

Sample Input 2:
4 3
1 2 3 3
Sample Output 2:
4

Sample Input 3:
5 6
1 3 3 3 5 
Sample Output 3:
2

Problem Link -> https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
*/

//optimal approach
//Using prefixSum algorithm

#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    map <int,int> preXor;
    int  Xor = 0,count = 0;
    preXor[Xor]++;
    for(int i = 0; i < a.size(); i++){
        Xor = Xor ^ a[i];
        count += preXor[Xor^b];
        preXor[Xor]++;
    }
    return count;
}



