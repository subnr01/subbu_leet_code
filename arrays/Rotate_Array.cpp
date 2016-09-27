/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].


Find three ways of coming up with the solution:
*/


class Solution {
public:
      void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k==0 || nums.size()==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
