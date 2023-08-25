/*
1021. Remove Outermost Parentheses

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

Constraints:
1 <= s.length <= 10^5
s[i] is either '(' or ')'.
s is a valid parentheses string.

Problem Link -> https://leetcode.com/problems/remove-outermost-parentheses/submissions/
*/

//own approach

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int l = 0,r = 0,f=0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                l++;
            }
            else{
                r++;
            }
            if(l != r and f != 0){
              if(s[i] == '('){
                r--;
              }
              else{
                l--;
              }
                ans += s[i];
            }
            f = 1;
            if(l == r){
              l = 0;
              r = 0;
              f = 0;
            }
        }
        return ans;
    }
};