class Solution {
public:

int BelowMid(int M, vector<int>& nums){
    if(!nums.size() || M<nums[0]) return 0;

    int l = -1, r = nums.size();
    while(l+1<r){
        int mid = (l+r)/2;
        if(nums[mid]>M){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    return l+1;

}

int findNth(int N, vector<int>& nums1, vector<int>& nums2){
    int l, r ;
    int n = nums1.size();
    int m = nums2.size();
    if(n) {
        l = nums1[0];
        r = nums1[n-1];
    }
    if(m){
        l = min(l, nums2[0]);
        r = max(r, nums2[m-1]);
    }

    l = l-1, r = r+1;

    while(l+1<r){
        int mid = (l+r)/2;
        int x = BelowMid(mid,nums1);
        int y = BelowMid(mid,nums2);

        if(x+y>=N){
            r = mid;
        }
        else{
            l = mid;
        }        
    }

    return r;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        double x = findNth((n+m+1)/2, nums1, nums2);

        if((n+m)%2) return x;

        x += findNth((n+m+1)/2+1, nums1, nums2);

        return x/2;
        
    }
};
