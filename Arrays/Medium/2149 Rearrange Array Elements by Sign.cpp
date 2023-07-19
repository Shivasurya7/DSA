/*
2149. Rearrange Array Elements by Sign

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:
	1.Every consecutive pair of integers have opposite signs.
	2.For all integers with the same sign, the order in which they were present in nums is preserved.
	3.The rearranged array begins with a positive integer.
	4.Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
	 

Example 1:
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

Example 2:
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].

Constraints:
2 <= nums.length <= 2 * 10^5
nums.length is even
1 <= |nums[i]| <= 10^5
nums consists of equal number of positive and negative integers.
*/

//naive approach (not optimal)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        if(nums[0] < 0){
            for(int j = 1; j < nums.size(); j++){
                if(nums[j] > 0){
                    int t = nums[j];
                    for(int k = j; k > 0;k--){
                        nums[k] = nums[k-1];
                    }
                    nums[0] = t;
                    break; 
                }
            }
        }
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > 0 and  nums[i+1] < 0){
                continue;
            }
            else if(nums[i] < 0 and  nums[i+1] > 0){
                continue;
            }
            else{
                if(nums[i] > 0){
                    for(int j = i+2; j < nums.size(); j++){
                        if(nums[j] < 0){
                            int t = nums[j];
                            for(int k = j; k > i+1;k--){
                                nums[k] = nums[k-1];
                            }
                            nums[i+1] = t;
                            break; 
                        }
                    }
                }
                else{
                    for(int j = i+2; j < nums.size(); j++){
                        if(nums[j] > 0){
                            int t = nums[j];
                            for(int k = j; k > i+1;k--){
                                nums[k] = nums[k-1];
                            }
                            nums[i+1] = t;
                            break; 
                        }
                    }
                }
            }
        }
        return nums;
    }
};

// optimal approach tc - O(N) and sc - O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pi = 0, ni = 1;
        vector <int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                result[pi] = nums[i];
                pi += 2;
            }
            else{
                result[ni] = nums[i];
                ni += 2;
            }
        }
        return result;
    }
};