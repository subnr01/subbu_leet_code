/*

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i;
and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. 
You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

*/

//DP
class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        if (n < 2) return 0;
        vector<int> hold(n, 0), sold(n, 0);
        hold[0] = -p[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], sold[i - 1] - p[i]);
            sold[i] = max(sold[i - 1], hold[i - 1] - fee + p[i]);
        }

        return sold[n - 1];
    }
};


//Greedy

/*
buy in - when current price higher than previous lowest point by more than amount of transaction fee, and set
current price as highest point;
sale out - when current price lower than prevous highest point by more than amount of transaction fee, and reset lowest, highest
update highest - only if highest is set;
update lowest - every day
*/
class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int profit = 0;
        int* lo = nullptr, *hi = nullptr, n = p.size();
        for (int i = 0; i < n; i++) {
            if (lo && !hi && p[i] - *lo > fee) hi = &p[i]; // buy in
            if (hi && p[i] > *hi) hi = &p[i]; // update highest
            if (hi && (*hi - p[i] > fee || i == n - 1)) { // sale out
                profit += *hi - *lo - fee;
                hi = nullptr;
                lo = nullptr;
            }

            if (!lo || p[i] < *lo) lo = &p[i]; // update lowest
        }
        return profit;
    }
