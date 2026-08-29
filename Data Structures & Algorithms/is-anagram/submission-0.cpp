class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> pref(26,0);
        if(s.size() != t.size()) return 0;
        for(int i=0;i<s.size();i++){
            pref[s[i]-'a']++;
            pref[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(pref[i]) return 0;
        }

        return 1;
    }
};
