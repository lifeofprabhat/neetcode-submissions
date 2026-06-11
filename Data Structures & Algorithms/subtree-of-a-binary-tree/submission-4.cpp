/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    
    string solve(TreeNode* root){
        if(!root) return "$";
        string lx = solve(root->left) + ",";
        string rx = solve(root->right) + ",";
        string fx = "(" + lx + to_string(root->val) +rx + ")";

         return fx;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       string x = solve(root);
       string y = solve(subRoot);
       return x.find(y) != string::npos;
        
    }
};
