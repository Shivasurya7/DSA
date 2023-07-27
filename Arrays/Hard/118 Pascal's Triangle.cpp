/*
118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30

Problem Link -> https://leetcode.com/problems/pascals-triangle/description/
*/

//my own approach

class Solution {
public:
    vector<vector<int>> generate(int num) {
        if(num == 1){
            return {{1}};
        }
        else if(num == 2){
            return {{1},{1,1}};
        }
        vector<vector<int>> tri;
        tri.push_back({1});
        tri.push_back({1,1});
        vector <int> t;
        int n;
        for(int i = 2; i < num; i++){
            t.push_back(1);
            n = i-1;
            for(int j = 0; j < n; j++){
                t.push_back(tri[n][j] + tri[n][j+1]);
            }
            t.push_back(1);
            tri.push_back(t);
            t.erase(t.begin(),t.end());
        }
        return tri;
    }
};