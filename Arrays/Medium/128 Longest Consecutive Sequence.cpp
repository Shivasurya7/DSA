/*
128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 
Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

//my approach

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int c = 1,maxi = 1;
        for(int i = 0; i < nums.size()-1; i++){
            int  t = nums[i+1] - nums[i];
            if(t == 1){
                c++;
                maxi = max(c,maxi);  
            }
            else if(t == 0){
                continue;
            }
            else{
                c = 1;
            }
        }
        return maxi;
    }
};