/*
125 Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

//two pointers concept
class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122) or (s[i] >= 48 and s[i] <= 57) ){
                if((s[i] >= 65 and s[i] <= 90)){
                    t += s[i]+32;
                }
                else{
                    t += s[i];
                }
            }
        }
        for(int i = 0,j=t.length()-1; i < (t.length()/2); i++,j--){
            if(t[i] != t[j]){
                return false;
            }
        }
        return true;
    }
};

// recursion concept

class Solution {
public:
    bool checkPalindrome(string t,int n=0){
        if(t.length()==0 or t.length() == 1){
            return true;
        }
        if(t[n] != t[(t.length()-n)-1]){
            return false;
        }
        if(n != (t.length()/2)-1){
            return checkPalindrome(t,n+1);
        }      
        return true;
    }
    bool isPalindrome(string s) {
        string t = "";
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122) or (s[i] >= 48 and s[i] <= 57) ){
                if((s[i] >= 65 and s[i] <= 90)){
                    t += s[i]+32;
                }
                else{
                    t += s[i];
                }
            }
        }
        return checkPalindrome(t);
    }
};
