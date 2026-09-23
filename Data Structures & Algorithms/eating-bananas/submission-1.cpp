class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long l = 0, r = 1e9+2;

        long ans = -1;

        while(l+1<r){
            long mid = (l+r)/2;
            long tot =0;

            for(int x : piles){
                tot += (x/mid);
                if(x%mid) tot++;
            }

            if(tot<=h){
                ans = mid;
                r = mid;
            }
            else{
                l =mid;
            }
        }

        return ans;
        
    }
};
