class Solution {
public:
    
    int dp[1010][1010];
    
    string longestPalindrome(string s) {
        
        string t=s;
        
        if(s.size()<=1) return s;
        
        int n=s.size();
        int mx=1,mxid=0;
        
        for(int i=0;i<n;i++)
        {
            int l=i-1 ,r=i;
            
            while(l>=0 and r<n and s[l]==s[r])
            {
              if((r-l+1)>mx) 
              {
                  mx=r-l+1;
                  mxid=l;
              }
              
              l--; r++; 
                
             }
            
             l=i-1,r=i+1;
            while(l>=0 and r<n and s[l]==s[r])
            {
              if((r-l+1)>mx) 
              {
                  mx=r-l+1;
                  mxid=l;
              }
              
              l--; r++; 
                
             }
        }
        
        return s.substr(mxid, mx);
        
    }
};