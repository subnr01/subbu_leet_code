/*

Maximum Swap

Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.

*/

//Related topics
// array, math

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        swaponce(s);
        int l = stoi(s);
        return l;
    }
private:
    void swaponce(string& s) {
        for (int i = 0; i < s.size(); i++) {
            int maxpos = i;
            for (int j = s.size() - 1; j > i; j--) {
                if (s[j] > s[maxpos]) {
                    maxpos = j;
                }
            }
            if (maxpos != i) {
                swap(s[i], s[maxpos]);
                break;
            }
        }
    }
};


//DP
class Solution {
public:
    int maximumSwap(int num) {
    string numString = to_string(num);
    int n = numString.length();
    vector<int> dpPosition(n, -1);
        
    int curMaxPos = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (numString[i] > numString[curMaxPos]) {
            curMaxPos = i;
        }
        dpPosition[i] = curMaxPos;
    }
        
    for (int i = 0; i < n; i++) {
        if(numString[dpPosition[i]] != numString[i]) {
            swap(numString[i], numString[dpPosition[i]]);
            break;
        }
    }
        
    return stoi(numString);
}
};
