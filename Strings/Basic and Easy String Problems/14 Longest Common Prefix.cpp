/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

Problem Link -> https://leetcode.com/problems/longest-common-prefix/description/
*/

//own approach

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        int f = 1,in=0;
        string s = "";
        char c;
        while(f){
            if(in >= strs[0].length()){
                break;
            }
            c = strs[0][in];
            for(int i = 0; i < strs.size(); i++){
                if(c != strs[i][in]){
                    f = 0;
                }
            }
            if(f){
                s += c;
                in++;
            }
        }
        return s;
    }
};