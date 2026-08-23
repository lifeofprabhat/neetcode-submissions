class Solution {
public:


int eraseOverlapIntervals(vector<vector<int>>& intV) {

   sort(intV.begin(), intV.end(), [](vector<int>&a,vector<int>&b){
    return a[1]<b[1];
   });

   int n = intV.size();

   vector<int> dp(n+1,0);

   

   for(int i=1;i<n;i++){
     dp[i] = dp[i-1];

     int l = -1, r=i;
     int curr = -1;
     while(l+1<r){
        int mid = (l+r)/2;
        if(intV[mid][1]<=intV[i][0]){
            curr = mid;
            l = mid;
        }
        else{
            r = mid;
        }
     }
      if(curr != -1){
        dp[i] = max(dp[i], dp[curr]+1);
      }
   }

  return n - dp[n-1]-1;
        
 }
};
