/*
74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m  = matrix[0].size();
        int l = 0, h = (n*m)-1,mid;
        while(l <= h){
            mid = (l+h)/2;
            if(matrix[mid/m][mid%m] == target){
                return true;
            }
            if(matrix[mid/m][mid%m] < target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return false;
    }


