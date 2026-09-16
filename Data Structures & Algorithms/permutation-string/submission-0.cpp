class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m<n) return 0;

        vector<int> freq(26,0), ref(26,0);
        
        for(auto c : s1) ref[c-'a']++;

        for(int i=0; i<n-1;i++) freq[s2[i]-'a']++;
       
        for(int i = n-1;i<m;i++){
            freq[s2[i]-'a']++;
            bool ok =true;
            for(int j=0;j<26;j++)
              if(freq[j] != ref[j]) ok = false;
            if(ok) return true;
            //cout<<i-n-1<<endl;
            freq[s2[i-n+1]-'a']--;
        }
         
        
       return 0; 
        
    }
};
