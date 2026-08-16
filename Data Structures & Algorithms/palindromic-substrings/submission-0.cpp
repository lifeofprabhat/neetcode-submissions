class Solution {
public:
    int countSubstrings(string s) {

       
        
        if(s.size()<=1) return 1;
        
        int n=s.size();
        vector<vector<bool>> ok(n+1,vector<bool>(n+1,0));
        int mx=1,mxid=0;
        
        for(int i=0;i<n;i++)
        {
            int l=i-1 ,r=i;
            
            while(l>=0 and r<n and s[l]==s[r])
            {
              
              ok[l][r] = 1;
              l--; r++; 
                
             }
            
             l=i-1,r=i+1;
             ok[i][i] = 1;
            while(l>=0 and r<n and s[l]==s[r])
            {
             
              ok[l][r]=1;
              l--; r++; 
                
             }
        }
        
     int ans = 0;

     for(int i=0;i<n;i++)
       for(int j=i;j<n;j++)
         if(ok[i][j]) ans++;

    return ans;
        
    }
};
