
/*


Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that
adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


*/


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }
        
        //sum should be subtracted before the check
        sum-=root->val;
        
        if(!root->right && !root->left) {
            return sum == 0;
        }
        
      // do not forget this OR comdition
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
        
    }
};
