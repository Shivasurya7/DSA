/*
136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
 

Constraints:
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
*/

//my approach

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        for(int i = 0; i < nums.size(); i++){
            int f = 1;
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] == nums[j] and i != j){
                    f = 0;
                    break;
                }
            }
            if(f){
                return nums[i];
            }
        }
        return 1;
    }
};


/*
Optimal Approach(Using XOR):
 
Intuition:
Two important properties of XOR are the following:

XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

Here all the numbers except the single number appear twice and so will form a pair. Now, if we perform XOR of all elements of the array, the XOR of each pair will result in 0 according to the XOR property 1. The result will be = 0 ^ (single number) = single number (according to property 2).

So, if we perform the XOR of all the numbers of the array elements, we will be left with a single number.

Approach:
We will just perform the XOR of all elements of the array using a loop and the final XOR will be the answer.

Dry run:

Assume the given array is: [4,1,2,1,2]
XOR of all elements = 4^1^2^1^2
      = 4 ^ (1^1) ^ (2^2)
      = 4 ^ 0 ^ 0 = 4^0 = 4
Hence, 4 is the single element in the array.

Time Complexity: O(N), where N = size of the array.
Reason: We are iterating the array only once.
Space Complexity: O(1) as we are not using any extra space.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++){
           x = x ^ nums[i];
        }
        return x;
    }
};

