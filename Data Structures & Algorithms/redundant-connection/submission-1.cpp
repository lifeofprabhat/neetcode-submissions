class Solution {
public:
    
    vector<int> par;
    vector<int> sz;

    int find(int node){
        if(par[node] != -1)
          return par[node] = find(par[node]);

        return node;
    }

    void unite(int a, int b){
         a = find(a);
         b = find(b);

        if(sz[a] >= sz[b]){
            par[b] = a;
            sz[a] += sz[b];
        }
        else{
            par[a] = b;
            sz[b] += sz[a];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //adj.resize(n+1);
        par.resize(n+1, -1);
        sz.resize(n+1,1);


        for(auto v : edges){
            int  a = find(v[0]);
            int b = find(v[1]);

            if(a != b) unite(a,b);
            else return {v[0], v[1]};

        }

        return {};
     
    }
};
