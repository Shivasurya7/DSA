/*
Ninja And The Second Order Elements
Problem Statement
Ninja is a brilliant student in the class and hence his teacher
assigned him a problem.

He has been given an array 'A' of 'N' unique non-negative
integers and has been asked to find the second largest and
second smallest element from the array.

Your task is to return two elements (second largest and
second smallest) as another array of size 2.

Sample Input 1 :
4
3 4 5 2
Sample Output 1 :
4 3
Explanation For Sample Input 1 :
The second largest element after 5 is 4 only and the second smallest element after 2 is 3.

Sample Input 2 :
5
4 5 3 6 7
Sample Output 2 :
6 4

Constraints:
2 ≤ A.Length ≤ 10^5
0 ≤ A[i] ≤ 10^9
It is guaranteed that the sum of lengths of ‘A’ is ≤ 10^5 for all test cases.

Time limit: 1 sec
*/

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int max1,max2,min1,min2;
    max1 = max2 = min1 = min2 = a[0];
    for(int i = 0; i < n; i++){
        if(max1 < a[i]){
            max2 = max1;
            max1 = a[i];
        }
        else{
            if(max1 == max2){
                max2 = a[i];
            }
            else if(max2 < a[i]){
                max2 = a[i];
            }
        }
        if(min1 > a[i]){
            min2 = min1;
            min1 = a[i];
        }
        else{
            if(min1 == min2){
                min2 = a[i];
            }
            else if(min2 > a[i]){
                min2 = a[i];
            }
        }
    }
    return {max2,min2};
}
