/*
229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?

Problem Link -> https://leetcode.com/problems/majority-element-ii/description/
*/

//optimal approach (using Moore’s Voting Algorithm):
//same method used in this problem -> 169. Majority Element (Array -> Medium)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0,c2 = 0,el1 = INT_MIN,el2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(c1 == 0 and nums[i] != el2){
                c1 = 1;
                el1 = nums[i];
            }
            else if(c2 == 0 and nums[i] != el1){
                c2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1){
                c1++;
            }
            else if(nums[i] == el2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        int n = nums.size()/3;
        c1 = c2 = 0;
        for(int  i = 0; i < nums.size(); i++){
            if(nums[i] == el1){
                c1++;
            }
            if(nums[i] == el2){
                c2++;
            }
        }
        vector <int> result;
        if(c1 > n){
            result.push_back(el1);
        }
        if(c2 > n){
            result.push_back(el2);
        }
        return result;
    }
};