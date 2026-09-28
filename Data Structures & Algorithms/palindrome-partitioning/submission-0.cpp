class Solution {
public:
    bool ok[22][22];
    vector<vector<string>> res;

    bool isP(string s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-1-i]) return false;
        }

        return true;
    }

   void dfs(string& s, int pos, int last, vector<string>& coll){
        if(pos == s.size()){
            if(last == pos)
             res.push_back(coll);
            return;
        }

        //finish at curr
        if(isP(s.substr(last, pos-last+1))){
            coll.push_back(s.substr(last, pos-last+1));
            dfs(s,pos+1,pos+1, coll);
            coll.pop_back();
        }

        dfs(s, pos+1,last,coll);

    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            ok[i][i] =1;
            for(int j=i+1;j<n;j++){
                if(isP(s.substr(i,j-i+1)))
                   ok[i][j] = 1;
            }
        }
        
        vector<string> coll;
        dfs(s,0,0,coll);
        return res;
        
    }
};
