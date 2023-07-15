/*
Linear Search

Problem Statement:
You are given an array 'ARR' containing 'N'
integers. You are also given an integer 'NUM',
and your task is to find whether 'NUM' is
present in the array or not.

If 'NUM' is present in the array, return the O-
based index of the first occurrence of 'NUM'
else, return -1.

Sample Input 1:
5 4
6 7 8 4 1
Sample Output 1 :
3
Explanation Of Sample Input 1:
4 is present at the 3rd index.

Sample Input 2:
4 2
2 5 6 2
Sample Output 2 :
0

Constraints:
1 <= N <= 1000
1 <= ARR[i] <= 1000
Time Limit: 1 sec

*/

int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}
