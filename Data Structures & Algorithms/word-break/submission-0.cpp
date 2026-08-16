class Solution {
public:
    bool wordBreak(string s, vector<string>& wl) {

      unordered_set<string> st;
      for(auto i : wl) st.insert(i);

      int n = s.size();
      s = "#"+s;
      vector<bool> dp(n+1, 0);
      dp[0] = 1;

      for(int i = 1;i<=n;i++){ 
        for(int j=i;j>=max(1,i-20);j--){
          string curr = s.substr(j,i-j+1);
          
          if(st.contains(curr)){
            if(dp[j-1]) dp[i] = 1;
          } 
        } 
      }
    
    return dp[n];
        
    }
};
