/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all
the empty parenthesis pairs that don't affect the one-to-one 
mapping relationship between the string and the original binary tree.




Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship 
between the input and the output.
*/

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) {
            return "";
        }
        string val = to_string(t->val);
        if (t->left) {
            val += "(" + tree2str(t->left) + ")";
        } else if (t->right) {
            val += "()";
        }
        
        if (t->right) {
            val += "(" + tree2str(t->right) + ")";
        }
        return val;
    }
    
};


//faster one seems, can you find why
class Solution {
public:
    
    void preorder(TreeNode *t, string &str) {
        str.append(to_string(t->val));
        if(t->left) {
            str.append("(");
            preorder(t->left,str);
            str.append(")");
        }
        if(!t->left && t->right) str.append("()");
        if(t->right) {
            str.append("(");
            preorder(t->right,str);
            str.append(")");
        }
        
    }
    
    string tree2str(TreeNode* t) {
        string str = "";
        if(!t) return str;
        preorder(t,str);
        return str;
    }
};

