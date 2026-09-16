class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.size(), m = t.size();
        if(m>n) return "";
        
        map<char,int> mp;
        for(int i=0;i<26;i++) mp['a'+i] = i;
        for(int i=0;i<26;i++) mp['A'+i] = 26+i;
        
        vector<int> freq(52,0), ref(52,0);
        
        for(auto c : t) ref[mp[c]]++;

        for(int i=0; i<m-1;i++) freq[mp[s[i]]]++;
        int l = 0, minL = 1e6;
        int idx= 0;
        for(int i = m-1;i<n;i++){
            freq[mp[s[i]]]++;
            bool ok =true;
            for(int j=0;j<52;j++)
              if(freq[j] < ref[j]) ok = false;

            while(ok){
               if(i-l+1<minL){
                minL = i-l+1;
                idx = l;
               }
               if(freq[mp[s[l]]]>ref[mp[s[l]]]){
                freq[mp[s[l]]]--;
                l++;
               }
               else break;
            }
            //cout<<i-n-1<<endl;
            //freq[s2[i-n+1]-'a']--;
        }
         
        
       if(minL==1e6) return "";

       return s.substr(idx, minL);
        
    }
};
