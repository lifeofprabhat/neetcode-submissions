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
public:
    vector<int> ans;
    void inoT(TreeNode* r){
        
        if(!r) return;
        
        inoT(r->left); 
        inoT(r->right);
        ans.push_back(r->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        inoT(root);
        return ans;
    }
};