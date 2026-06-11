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
    map<int,int> mp;
    TreeNode* bT(vector<int>& preo, vector<int>& ino, int inSt, int inEn,int& preIdx){
        if(inSt > inEn) return nullptr;
        TreeNode* curr = new TreeNode(preo[preIdx++]);
        int currInoIdx = mp[curr->val];
        curr->left = bT(preo, ino, inSt,currInoIdx-1,preIdx);
        curr->right = bT(preo, ino, currInoIdx+1, inEn, preIdx);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preo, vector<int>& ino) {
        int n = preo.size();
        for(int i=0;i<n;i++) mp[ino[i]] = i;
        int preIdx = 0;
        return bT(preo, ino, 0, n-1,preIdx);
       
    }
};
