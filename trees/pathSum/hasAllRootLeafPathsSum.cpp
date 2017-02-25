/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

*/


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        vector<int> path;
        
        pathSum_f(root, res, path, sum);
        return res;
        
    }
    
    
    void pathSum_f(TreeNode* root, vector<vector<int>> &res, vector<int> path, int sum) {
        if(!root) {
            return;
        }
        
        
        sum-=root->val;
        path.push_back(root->val);
        if(!root->right && !root->left) {
            if (sum == 0) {
                res.push_back(path);
            }
        }
        
        pathSum_f(root->left,  res, path, sum);
        pathSum_f(root->right, res, path, sum);
    }
};
