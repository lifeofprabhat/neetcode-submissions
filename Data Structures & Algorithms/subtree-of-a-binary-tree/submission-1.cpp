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
    unordered_set<string> st;
    string solve(TreeNode* root, bool bAdd=1){
        if(!root) return "$";
        string lx = solve(root->left,bAdd) + ",";
        string rx = solve(root->right,bAdd) + ",";
        string fx = lx + to_string(root->val) +rx;
        if(bAdd)
         st.insert(fx);

         return fx;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       solve(root);
       string y = solve(subRoot,0);
       return st.count(y);
        
    }
};
