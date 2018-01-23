/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int last = n-1;
        
        for ( int i = n - 2; i >=0; i--) {
            if ((i+nums[i]) >= last ) {
                last = i;
            }
        }
        
        return last == 0;
    }
};

//Another soln
class Solution {
public:        
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        
        int end = 0;        
        
        for (int i=0; i < nums.size(); ++i) {
            if (i > end) {
                return false;
            }
            
            end = max(end, i + nums[i]);
        }
        
        return true;
    }
};
