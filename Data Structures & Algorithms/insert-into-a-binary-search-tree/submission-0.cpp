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
    TreeNode* target = NULL;
    void findNode(TreeNode* root, int val){
        if(!root) return;
        
        target = root;

        if(root->val > val){
          findNode(root->left, val);
        }
        else
          findNode(root->right, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        findNode(root,val);
        TreeNode* newNode = new TreeNode(val);
        if(target->val > val){
            newNode->left = target->left;
            target->left = newNode;
        }
        else{
            newNode->right = target->right;
            target->right=newNode;
        }

        return root;
        
    }
};