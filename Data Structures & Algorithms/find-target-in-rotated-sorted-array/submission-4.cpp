class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       if(n==1) return {nums[0]==target ? 0 : -1};
       if(n==2){
        if(nums[0]==target) return 0;
        if(nums[1]==target) return 1;
        return -1;

       }

        int l = -1, r = n;
        
        int minIdx  = 0;
        while(l+1<r){
            int mid = (l+r)/2;
            if(nums[mid]>=nums[0]){
                l = mid;
            }
            else {
                r = mid;
            }
            
        }

       minIdx = r;
       cout<<minIdx<<endl;

       if(target<nums[0]){
        l = minIdx-1;
        r = n;
       }
       else{
        l = -1;
        r = minIdx;
       }

       int ans = -1;

       while(l+1<r){
        int mid = (l+r)/2;
        if(nums[mid]<target){
            l = mid;
        }
        else if(nums[mid]>target){
            r = mid;
        }
        else return mid;
       }

       return -1;
        
    }
};
