class Solution {
public:
   vector<vector<int>> dp;
   int dfs(string& s, int idx, int sum){
        if(idx==s.size()) return sum==0;
        if(sum<0) return 0;
        int tmp = 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        if(s[idx]=='(')
          tmp = dfs(s,idx+1,sum+1);
        else if(s[idx]==')')
          tmp = dfs(s,idx+1,sum-1);
        else{
            tmp |= dfs(s,idx+1,sum);
            tmp |= dfs(s,idx+1,sum+1);
            tmp |= dfs(s,idx+1,sum-1);
        }

        return dp[idx][sum]=tmp;

    }
    bool checkValidString(string s) {
        dp.resize(101,vector<int>(101,-1));
       return dfs(s,0,0);
    }
};
