/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to
nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

*/

//https://leetcode.com/problems/delete-and-earn/solution/

class Solution {
    public int deleteAndEarn(int[] nums) {
        final Map<Integer, Integer> values = new TreeMap<>();
        for (final int num : nums) {
            values.put(num, values.getOrDefault(num, 0) + num);
        }
        int pre = 0, cur = 0;
        for (final int num : values.keySet()) {
            if (!values.containsKey(num - 1)) {
                pre = cur;
                cur += values.get(num);
            } else {
                final int temp = Math.max(pre + values.get(num), cur);
                pre = cur;
                cur = temp;
            }
        }
        return cur;
    }
}

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};
