class Solution {
public:
    int trap(vector<int>& hts) {
        int n = hts.size();
        vector<int>suff(n), pref(n);

        pref[0] = hts[0];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],hts[i]);
        }
        suff[n-1] = hts[n-1];

        for(int i=n-2;i>=0;i--)
         suff[i] = max(suff[i+1],hts[i]);


        int ans = 0;

        for(int i=0;i<n;i++){
            ans += (min(suff[i],pref[i])-hts[i]);
        }

        return ans;
        
    }
};
