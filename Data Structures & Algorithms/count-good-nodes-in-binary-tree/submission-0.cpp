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
void dfs(TreeNode* root, int mx, int& ans)
{
    if(!root) return;

    if(root->val >= mx) ans++;
    mx = max(mx, root->val);
    dfs(root->left,mx, ans);
    dfs(root->right,mx, ans);
}
class Solution {
public:
    int goodNodes(TreeNode* root) {
     int ans = 0;
     dfs(root, -200, ans);
     return ans;  
    }
};
