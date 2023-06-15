/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

 vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1 and nums[0]== target){
            return {0,0};
        }

        int l =0, h  = nums.size() - 1,first=-1,last=-1,mid;

        while(l <= h){
            mid = (l+h)/2;
            if(nums[mid] >= target){
                first = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        l = 0;
        h = nums.size()-1;

         while(l <= h){
            mid = (l+h)/2;
            if(nums[mid] <= target){
                last = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }

      
       if(first == -1 or nums[first] != target){
             return {-1,-1};
        }
        else{
            return {first,last};
        }
    }


