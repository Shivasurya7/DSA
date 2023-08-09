/*
493. Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:
1 <= nums.length <= 5 * 10^4
-2^31 <= nums[i] <= 2^31 - 1

Problem Link -> https://leetcode.com/problems/reverse-pairs/
*/

//own approach (not optimal)
//using hashing concept

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        map <int,int> fre;
        int c = 0;
        long long k;
        for(int i = 0; i < nums.size(); i++){
            for(auto f : fre){
                k = nums[i];
                k *= 2;
                if(f.first > k){
                    c += f.second;
                }
            }
            fre[nums[i]]++;
        }
        return c;
    }
};



