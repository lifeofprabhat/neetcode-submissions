/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> umap;
    void dfs(Node* node){

        Node* root = new Node(node->val);
        umap[node] = root;

        for(auto child : node->neighbors){
            if(umap.contains(child)) continue;
            dfs(child);
        }

    }
    Node* cloneGraph(Node* node) {

        if(!node) return node;
        dfs(node);
        
        for(auto [a,b] : umap){
            for(auto child : a->neighbors){
                b->neighbors.push_back(umap[child]);
            }
        }
      
      return umap[node];
        
    }
};
