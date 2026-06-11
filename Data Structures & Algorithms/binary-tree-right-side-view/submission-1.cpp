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
    vector<int> rightSideView(TreeNode* root) {

    //vector<vector<int>> ans;
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        //vector<int>tmp;
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            if(i== n-1) res.emplace_back(curr->val);
            q.pop();
            //tmp.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        //ans.push_back(tmp);
    }

    //for(auto &v : ans){
      //  res.emplace_back(v.back());
    //}
    return res;
       
        
    }
};
