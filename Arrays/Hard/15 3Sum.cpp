/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5

Problem Link -> https://leetcode.com/problems/3sum/
*/

//better than brutfource approach (not optimal)

/*
Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int r;
        vector <int> temp;
        set <vector<int>> st;
        for(int i = 0; i < nums.size(); i++){
            map <int,int> fre;
            for(int j = i+1; j < nums.size(); j++){
                r = -(nums[i] + nums[j]);
                if(fre[r] > 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(r);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    temp.erase(temp.begin(),temp.end());
                }
                fre[nums[j]]++;
            }
        }
        vector <vector<int>> result(st.begin(),st.end());
        return result;
    }
};

//optimal approach

/*
Time Complexity: O(NlogN)+O(N2), where N = size of the array.
Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <vector<int>> result;
        int j,k;
        for(int i = 0; i < nums.size()-1; i++){
            if(i > 0 and nums[i] == nums[i-1]){
                continue;
            }
            j = i+1;
            k = nums.size()-1;
            while(j < k){
                int t = nums[i] + nums[j] + nums[k];
                if(t == 0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k and nums[j] == nums[j-1]){
						j++;
                    }
                    while(j < k and nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else if( t > 0){
                    k--;
                }
                else{
                    j++;
                }  
            }
        }
        return result;
    }
};

