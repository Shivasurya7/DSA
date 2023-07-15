/*
189 Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

//my solution

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size(),t = k % n;
        for(int i = 0; i < t; i++){
            int temp = a.back();
            a.pop_back();
            a.insert(a.begin(),temp);
        }
    }
};

//optimal solution:

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

/*Optimized Approach(without using any extra space): Using “Reversal Algorithm” 
This is a straightforward method. The steps are as follows:

Step 1: Reverse the subarray with the last d elements (reverse(arr+n-d, arr+n)).
Step 2: Reverse the subarray with the first (n-d) elements (reverse(arr, arr+n-d)).
Step 3: Finally reverse the whole array (reverse(arr, arr+n)).
Assume the given array is {1,2,3,4,5,6,7} and d = 3.
Step 1 -> 1 2 3 4 7 6 5
Step 2 -> 4 3 2 1 7 6 5
Step 3 -> 5 6 7 1 2 3 4
*/