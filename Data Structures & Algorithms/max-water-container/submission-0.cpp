class Solution {
public:
    int maxArea(vector<int>& hts) {
        
        int n = hts.size();
        int l = 0;
        int r = n-1;
        int ans = 0;

        while(l<r){

            ans = max(ans,(r-l)*min(hts[l],hts[r]));
            if(hts[l]<=hts[r]) l++;
            else r--;

        }
        return ans;
        
    }
};
