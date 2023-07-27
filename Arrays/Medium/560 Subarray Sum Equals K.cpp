/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7

Problem Link -> https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

//optimal approach (using prefixsum algorithm)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0,t,c=0;
        map <int,int> prefixSum;
        for(int i = 0; i< nums.size(); i++){
            prefixSum[sum]++;
            sum += nums[i];
            t = sum - k;
            c += prefixSum[t];
        }
        return c;
    }
};

/*
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
*/