class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int ans = k;
        for(int i=0;i<26;i++){
            int l =0, others = 0;
            for(int r=0;r<s.size();r++){
              if(s[r] !=('A' + i)) others++;
            
              while(others>k){
                if(s[l]!=('A' + i)) others--;
                l++;
               }

              ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};
