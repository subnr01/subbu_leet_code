/*
Given a binary tree, return all duplicate subtrees. 
For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
      
The following are two duplicate subtrees:

      2
     /
    4
and

    4

*/

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> dups;
        serialize(root, map);
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second.size() > 1) {
                dups.push_back(it->second[0]);
            }
        }
        return dups;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
        if (!node) return "";
        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};

