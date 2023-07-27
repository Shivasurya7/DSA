/*
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

Problem Link -> https://leetcode.com/problems/spiral-matrix/description/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size(),c = matrix[0].size();
        int right = c-1,left = 0,top = 0,bottom = r-1;
        vector <int> result;
        while(top <= bottom and left <= right){
            
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){ // Incase of single row matrix we need to check this conditon 
                for(int i = right; i >= left; i--){
                   result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){ // Incase of single column matrix we need to check this conditon
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};