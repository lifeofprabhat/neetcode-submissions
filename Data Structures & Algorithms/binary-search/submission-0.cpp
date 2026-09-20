class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n, ans = -1;

        while(l+1<r){
            int mid = (l+r)/2;
            if(nums[mid]<target){
                l  = mid;
            }
            else if(nums[mid]>target){
                r = mid;
            }
            else {
                 return mid;
            }
        }

        return -1;
    }
};
