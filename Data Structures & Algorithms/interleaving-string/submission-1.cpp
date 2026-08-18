class Solution {
public:

    vector< vector<int>>dp;
    bool bt(string& s1, string& s2, string& s3, int i, int j, int k){
      if(k==s3.size())
      { 
        return 1;
      }

      if(dp[i][j] != -1) return dp[i][j];

      if(i<s1.size()){
        if(s1[i]==s3[k] && bt(s1,s2,s3,i+1,j,k+1))
         return dp[i][j]=1;
      }

      if(j<s2.size()){
        if(s2[j]==s3[k] && bt(s1,s2,s3,i,j+1,k+1))
         return dp[i][j]=1;
      }
      
      return dp[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
    int z = s3.size();
    int y = s2.size();
    int x = s1.size();

    if(x+y!=z) return 0;
    
    dp.resize(x+1,vector<int>(y+1,-1));

    int i,j,k;
    i=j=k =0;

    return bt(s1,s2,s3,i,j,k);

    
}
};
