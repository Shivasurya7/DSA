/*
410. Split Array Largest Sum

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= k <= min(50, nums.length)
*/

class Solution {
public:
    int isPossible(vector<int>& arr,int m,int s){
        int sum = 0,c=0;
        for(int  i = 0; i < arr.size(); i++){
            if(arr[i] > s){
                return 0;
            }
            if(sum + arr[i] > s){
                c++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
        if(c < m){
            return 1;
        }
        else{
            return 0;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int l = nums[0],h = 0,mid,ans;

        for(int i = 0; i< nums.size(); i++){
            if(l < nums[i]){
                l = nums[i];
            }
            h += nums[i];
        }
        while(l <= h){
            mid = (l+h)/2;
            if(isPossible(nums,k,mid)){
                h = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

//own approach (using recursion but not optimal)

#include <bits/stdc++.h>
using namespace std;

vector <int> possibleMax(vector <int> nums,int k,int l = 1,int j = 0,int sumMax = 0){
    int sum = 0;
    static vector <int> result;
    if(l == k){
        for(int i = j; i < (int)nums.size(); i++){
            sum += nums[i];
        }
        if(sum > sumMax){
            result.push_back(sum);
        }
        else{
            result.push_back(sumMax);
        }
        return result;
    }
   for(int i = j; i < (int)nums.size()-(k-l); i++){
        sum += nums[i];
        possibleMax(nums,k,l+1,i+1,(sum > sumMax)? sum:sumMax);
   }
   return result;
}

int main()
{
    vector <int> nums,result;
    int n,t,k;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t;
        nums.push_back(t);
    }
    cin>>k;
    result = possibleMax(nums,k);
    int l = result[0];
    for(int i = 1; i < (int)result.size(); i++){
        if(l > result[i]){
            l = result[i];
        }
    }
    cout<<l;
}