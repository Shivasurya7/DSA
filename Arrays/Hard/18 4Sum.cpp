/*
18.4Sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:
1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

Problem Link -> https://leetcode.com/problems/4sum/
*/

//better than brutfource approach (not optimal)
//same algorithm used in 3Sum problem

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        long long t,sum=0;
        vector <int> temp;
        set <vector<int>> st;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j< nums.size(); j++){
                map <int,int> fre;
                for(int k = j+1; k < nums.size(); k++){
                    sum = nums[i] + nums[j];
                    sum += nums[k];
                    t = (long)target - sum;
                    if(fre[t] > 0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(t);
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                        temp.erase(temp.begin(),temp.end());
                    }
                    fre[nums[k]]++;
                }
            }
        }
        vector <vector<int>> result(st.begin(),st.end());
        return result;
    }
};

//optimal approach
//same algorithm used in 3Sum problem

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector <vector<int>> result;
        int k,l;
        long long sum;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 and nums[i] == nums[i-1]){
                    continue;
                }
            for(int j = i+1; j < nums.size(); j++){
                if(j > i+1 and nums[j] == nums[j-1]){
                    continue;
                }
                k = j+1;
                l = nums.size()-1;
                while(k < l){
                    sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k < l and nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k < l and nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        return result;
    }
};



