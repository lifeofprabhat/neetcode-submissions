class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    int l = -1002, r = 1002;
    int ans = -1001;
    while(l+1<r){
      int mid= (l+r)/2;
      int cnt = 0;
      for(auto x :  nums){
        if(x>=mid) cnt++;
      }
      if(cnt>=k){
        ans = mid;
        l = mid;
      }
      else 
         r = mid;
    }

    return ans;
        
    }
};
