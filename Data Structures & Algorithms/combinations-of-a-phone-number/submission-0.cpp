class Solution {
public:
vector<char> adj[10];
vector<string> ans;

void dfs(string& inp, int pos, string& curr ){
    if(pos==inp.size()){
        ans.push_back(curr);
        return;
    }

    int N = inp[pos]-'0';

    for(int i=0;i<adj[N].size();i++){
        curr.push_back(adj[N][i]);
        dfs(inp, pos+1,curr);
        curr.pop_back();
    }
}
    
    vector<string> letterCombinations(string inp) {
        adj[2].insert(adj[2].end(), {'a','b','c'});
        adj[3].insert(adj[3].end(), {'d','e','f'});
        adj[4].insert(adj[4].end(), {'g','h','i'});
        adj[5].insert(adj[5].end(), {'j','k','l'});
        adj[6].insert(adj[6].end(), {'m','n','o'});
        adj[7].insert(adj[7].end(), {'p','q','r','s'});
        adj[8].insert(adj[8].end(), {'t','u','v'});
        adj[9].insert(adj[9].end(), {'w','x','y','z'});

        if(inp.size() == 0) return ans;

        string curr;
        dfs(inp, 0, curr);
        return ans;
        
    }
};
