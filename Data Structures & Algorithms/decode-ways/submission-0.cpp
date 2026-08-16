class Solution {
public:
    set<string>st; 
    vector<int> dp;

    int solve(string s, int pos){
      if(pos==s.size()) return 1;
      if(dp[pos] != -1) return dp[pos];
      int ans = 0;
      string x = s.substr(pos,1);
      if(st.contains(x))
          ans += solve(s,pos+1);

      if(pos<s.size()-1){
          string y = s.substr(pos,2);
          if(st.contains(y))
          ans += solve(s,pos+2);
      }

      return dp[pos]=ans;

    }
    int numDecodings(string s) { 
      for(int i=1;i<=26;i++)
        st.insert(to_string(i));
      dp.resize(s.size()+2, -1);
      return solve(s,0);
        
    }
};
