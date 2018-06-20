/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and
node values with a subtree of s. A subtree of s is a tree consists of a node in s
and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

*/


class Solution {
public:

    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (!s) {
            return false;
        }
        if (isSametree(s, t)) {
            return true;
        }
        
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSametree(TreeNode *t1, TreeNode *t2) 
    {
        if (!t1 || !t2) {
            return (t1 == t2);
        }
        
        return t1->val == t2->val && isSametree(t1->left, t2->left) && isSametree(t1->right, t2->right);
    }
};

