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
    TreeNode* ans = NULL;
    
    bool solve(TreeNode* root, int p, int q)
    {
        if(!root) return false;
        bool rx = solve(root->right,p,q);
        bool lx = solve(root->left,p,q);
        if(root->val == p &&  rx ){           
                ans = root;
                return true;
        }
        else if(root->val == q && lx ){
            ans = root;
            return true;
        }

        if(rx && lx && !ans)
           ans = root;

        if(root->val == p || root->val == q)
           return true;
        
        return (lx || rx);

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int pi = p->val;
        int qi = q->val;
        if(pi>qi) swap(pi,qi);
        solve(root,pi,qi);
        return ans;
    }
};
