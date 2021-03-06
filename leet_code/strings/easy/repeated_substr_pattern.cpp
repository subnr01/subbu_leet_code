/*

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple
copies of the substring together. You may assume the given string consists of lowercase English letters only
and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

*/


class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if(len < 1) return false;
        for(int i = 1; i <= len / 2; i++){
            if(len % i == 0){
                nextStr = leftShift(str, i);
                if(nextStr == str) return true;
            }
        }
        return false;
    }
    
    string leftShift(string &str, int l){
        /*
        Remove a character(s) and add it at the end
        abab 
        ret = baba
        ret = abab
        */
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};
