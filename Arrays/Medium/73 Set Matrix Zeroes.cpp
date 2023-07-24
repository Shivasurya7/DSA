/*
73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]] 

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1

Follow up:
1. A straightforward solution using O(mn) space is probably a bad idea.
2. A simple improvement uses O(m + n) space, but still not the best solution.
3. Could you devise a constant space solution?
*/

//my approach

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <pair<int,int>> ind;
        int m = matrix.size(),n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    ind.push_back({i,j});
                }
            }
        }
        
        for(int k = 0; k < ind.size(); k++){
            for(int i = 0; i < m; i++){
                matrix[i][ind[k].second] = 0;
            }
            for(int i = 0; i < n; i++){
                matrix[ind[k].first][i] = 0;
            }
        }
    }
};