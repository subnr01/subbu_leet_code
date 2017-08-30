/*
Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.


*/



class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        
        // biggest, one more digit, 10...01
        //101, 1001, 10001, etc
        candidates.insert(long(pow(10, l)) + 1);
        
        //99, 999, 9999
        // smallest, one less digit, 9...9 or 0
        candidates.insert(long(pow(10, l - 1)) - 1);
        
        // the closest must be in middle digit +1, 0, -1, then flip left to right
        // Divide the string by half and convert it into a number
        long prefix = stol(n.substr(0, (l + 1) / 2));
        
        // Find the other candidates
        for ( long i = -1; i <= 1; ++i ) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        
        
        long num = stol(n), minDiff = LONG_MAX, diff, minVal;
        candidates.erase(num);
        for ( long val : candidates ) {
            diff = abs(val - num);
            if ( diff < minDiff ) {
                minDiff = diff;
                minVal = val;
            } else if ( diff == minDiff ) {
                minVal = min(minVal, val);
            }
        }
        return to_string(minVal);
    }
};
