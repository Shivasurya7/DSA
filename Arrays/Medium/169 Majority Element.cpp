/*
169. Majority Element

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than n / 2 times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

//my approach 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> fre;
        for(int i = 0; i < nums.size(); i++){
            fre[nums[i]]++;
            if(fre[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        for(auto it = fre.begin(); it != fre.end(); it++){
            if(it->second > nums.size()/2){
                return it->first;
            }
        }
        return -1;
    }
};

/*
Optimal Approach: Moore’s Voting Algorithm:
Intuition:
If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

Approach: 
1.Initialize 2 variables:
	Count –  for tracking the count of element
	Element – for which element we are counting
2.Traverse through the given array.
	If Count is 0 then store the current element of the array as Element.
	If the current element and Element are the same increase the Count by 1.
	If they are different decrease the Count by 1.
3.The integer present in Element should be the result we are expecting 

Basically, we are trying to keep track of the occurrences of the majority element and minority elements dynamically. 
That is why, in iteration 4, the count becomes 0 as the occurrence of Element and the occurrence of the other elements are the same. 
So, they canceled each other. This is how the process works. 
The element with the most occurrence will remain and the rest will cancel themselves.

Here, we can see that 2 is the majority element. 
But if in this array, the last two elements were 3, then the Element variable would have stored 3 instead of 2. 
For that, we need to check if the Element is the majority element by traversing the array once more. 
But if the question guarantees that the given array contains a majority element, then we can bet the Element will store the majority one.

Time Complexity: O(N) + O(N), where N = size of the given array.
Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.

Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).

Space Complexity: O(1) as we are not using any extra space.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,ele;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            }
            else if(ele == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(ele == nums[i]){
                count++;
            }
        }
        if(count > nums.size()/2){
            return ele;
        }
        return -1;
    }
};