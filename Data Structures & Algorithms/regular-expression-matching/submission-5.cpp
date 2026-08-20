class Solution {
public:
   
    vector<vector<int>>dp;
    bool ok(string& s , string& t, int i, int j){
        if(j==t.size()) return i==s.size();

        if(dp[i][j]  != -1) return dp[i][j];

        bool match(0);
        if(i<s.size() &&(s[i]==t[j] || t[j]=='.'))
           match = 1;

        if(j<t.size()-1 && t[j+1]== '*'){
            return dp[i][j] = (ok(s,t,i,j+2) || (match &&(ok(s,t,i+1,j))));
        }

        if(match)
        return dp[i][j]=ok(s,t,i+1,j+1);

        return dp[i][j]=false;
        
    }
    bool isMatch(string s, string p) {

        

        dp.resize(s.size()+1, vector<int>(p.size()+1,-1));
    
        return ok(s,p,0,0);
        
    }
};
