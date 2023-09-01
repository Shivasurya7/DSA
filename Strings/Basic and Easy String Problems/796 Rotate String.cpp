/*
796. Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

Constraints:
1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

Problem Link -> https://leetcode.com/problems/rotate-string/description/
*/

//own approach

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        char c;
        string t = s;
        int n = s.length();
        for(int i = s.length()-1; i >= 0; i--){
            c = s[i];
            t = c+t;
            if(t.substr(0,n) == goal){
                return true;
            }
        }
        return false;
    }
};