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
    int ans = -1000;
    int maxSum(TreeNode* root){
        if(root == nullptr)
           return -1001;

        int lSum = maxSum(root->left);
        int rSum = maxSum(root->right);
        ans = max({ans, root->val, lSum, lSum+root->val, rSum, rSum+root->val,
                   lSum+root->val+rSum});

        int retVal = root->val + max({0,lSum, rSum});
        //cout<<root->val<<" "<<retVal<<endl;
        return retVal;

    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;

    }
};
