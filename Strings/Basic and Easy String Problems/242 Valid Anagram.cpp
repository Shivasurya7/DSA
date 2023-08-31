/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.

Problem Link -> https://leetcode.com/problems/valid-anagram/description/
*/

//own approach

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int a[26]= {0};

        for(int i = 0; i < s.length(); i++){
            a[s[i]-97]++;
        }
        for(int i = 0; i < s.length(); i++){
            a[t[i]-97]--;
        }
         for(int i = 0; i < 26; i++){
             if(a[i] != 0){
                 return false;
             }
         }
        return true;
    }
};