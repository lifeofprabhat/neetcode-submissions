class Solution {
public:
    bool vis[26];
    vector<int>adj1[27];
    vector<int>adj[27];
    //vector<int>freq;
    int cnt = 0;

    void dfs(int node){
        vis[node] =1;
        cnt+= adj[node].size();
        //cout<<node<<" "<<adj[node].size()<<endl;
        for(auto child : adj1[node]){
            if(!vis[child])
              dfs(child);
        }
    }
    vector<int> partitionLabels(string s) {

     for(int i=0;i<26;i++) {adj[i].clear(); adj1[i].clear(); vis[i]= 0; }

        for(int i=0;i<s.size();i++){
            adj[s[i]-'a'].push_back(i);
        }

        

        for(int i=0;i<26;i++){
            if(adj[i].size()>1){
                int l = adj[i][0]+1;
                int r = adj[i][adj[i].size()-1]-1;

                for(int k=l;k<=r;k++){
                    adj1[s[k]-'a'].push_back(i);
                    adj1[i].push_back(s[k]-'a');
                }
            }
        }
        
        vector<int>ans;

        for(int i = 0;i<s.size();i++){
          cnt = 0;
          if(!vis[s[i]-'a']){
            dfs(s[i]-'a');
            ans.push_back(cnt);
          }
        }

        return ans;
        
    }
};
