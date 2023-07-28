/*
119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]

Constraints:
0 <= rowIndex <= 33

Problem Link -> https://leetcode.com/problems/pascals-triangle-ii/description/
*/

//optimal approach

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector <int> result;
        long ans = 1;
        result.push_back(ans);
        for(int j = 1; j < n; j++){
            ans *= n-j;
            ans /= j;
            result.push_back(ans);
        }
        return result;
    }
};