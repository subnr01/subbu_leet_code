/*
Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n
and obeys the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has 
exactly k distinct integers

Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and
the [1, 1] has exactly 1 distinct integer: 1.


Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] 
has exactly 2 distinct integers: 1 and 2.

*/

/*
Soln
if you have n number, the maximum k can be n - 1;
if n is 9, max k is 8.
This can be done by picking numbers interleavingly from head and tail,

// start from i = 1, j = n;
// i++, j--, i++, j--, i++, j--

1   2   3   4   5
  9   8   7   6
out: 1 9 2 8 3 7 6 4 5
dif:  8 7 6 5 4 3 2 1
Above is a case where k is exactly n - 1
When k is less than that, simply lay out the rest (i, j) in incremental
order(all diff is 1). Say if k is 5:

     i++ j-- i++ j--  i++ i++ i++ ...
out: 1   9   2   8    3   4   5   6   7
dif:   8   7   6   5    1   1   1   1 

*/


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {
              //IMPORTANT, WHEN you pass post increment
              // to function, it gets evaluated as
              // the function call and hence
              // k, i and j all values change 
              // once you return form the funciton.
                res.push_back(k-- % 2 ? i++ : j--);
            }
            else {
                res.push_back(i++);
            }
        }

        return res;
    }
};
