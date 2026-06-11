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
    void inorderT(TreeNode* root,int& k, int& ans){
        if(root == nullptr || k <= 0) return;
        inorderT(root->left,  k,  ans);
        k--;
        if(k == 0 ) ans = root->val;
        inorderT(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorderT(root, k, ans);
        return ans;
        
    }
};
