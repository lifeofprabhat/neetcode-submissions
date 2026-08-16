class Solution {
public:
    string foreignDictionary(vector<string>& words) {

    vector<bool> pres(26,0);
    vector<int> adj[26];
    vector<int> indeg(26,0);

    int n = words.size();
    if(n<2) return words[0];

    auto process = [&](const string& a, const string& b){
        for(auto c : a) pres[c-'a']=1;
        for(auto c : b) pres[c-'a']=1;

        int x = a.size();
        int y = b.size();

        for(int i = 0;i<min(x,y);i++){
            if(a[i]==b[i]) continue;
            adj[a[i]-'a'].push_back(b[i]-'a');
            indeg[b[i]-'a']++;
            break;
        }

    };

    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string a = words[i];
            string b = words[j];
            if(a.starts_with(b) && a.size()>b.size()) return "";
            process(a,b);
        }
    }

    queue<int>q;
   
    int len = 0;
    for(int i=0;i<26;i++){
        if(pres[i]){
            len++;
            if(!indeg[i]){
                q.push(i);
            }
        }
    }

    string res = "";
    int vis[26] = {0};
    while(!q.empty()){
        auto curr = q.front();
        res+=('a'+curr);
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = 1;

        for(auto child : adj[curr]){
            if(--indeg[child] == 0){
                q.push(child);
            }
            
        }
    }
   
   if(res.size() == len) return res;
   return "";
        
    }
};
