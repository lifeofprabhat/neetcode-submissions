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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string tot = "";
      if(!root) return "N";
      tot = to_string(root->val);
      string ls = serialize(root->left);
      string rs = serialize(root->right);

      tot += {","+ls};
      tot += {"," + rs};
      return tot;
        
    }
    
    TreeNode* deHelper(string& data, int& i){
         TreeNode* root = NULL;
         if(i == data.size())
           return root;

        //stringstream path(data);



        string curr_val = "";
        //int& i = idx;
        while(i<data.size()){
            if(data[i]==',' && !curr_val.size()){
                i++;
                continue;
            }
            else if(data[i]==',' && curr_val.size()){
                if(curr_val == "N"){
                    i++;
                    return root;
                }

                root= new TreeNode(); 
                root->val = stoi(curr_val);
                i++;
                //cout<<root->val<<endl;
                break;

            }
            else{
                curr_val += data[i];
                i++;
            }
        }

       
       root->left =deHelper(data,i);
       root->right = deHelper(data,i);

       return root; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        data += ",";
        int idx = 0;
        return deHelper(data,idx);

       
        
    }
};
