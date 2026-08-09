class Solution {
public:
    vector<int> findOrder(int numC, vector<vector<int>>& preq) {

     vector<int> ind(1001,0);
     vector<int> adj[1001];

      for(auto v : preq){
         ind[v[0]]++;
         adj[v[1]].push_back(v[0]);
      }
        

        queue<int> q;

        for(int i=0;i<numC;i++){
            if(!ind[i])
              q.push(i);
        }
        
        vector<int> ans;

        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto child : adj[curr]){
               ind[child]--;
               if(!ind[child]) 
                  q.push(child);
            }
        }

        for(int i=0;i<numC;i++){
            if(ind[i]) return {};
        }

        return ans;
        
    }
};
