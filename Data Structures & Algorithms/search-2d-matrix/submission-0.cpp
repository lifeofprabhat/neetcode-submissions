class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int target) {
        int n = mtx.size();
        int m = mtx[0].size();

        int l = -1, r = n;
        int pr= -1;
        while(l+1<r){
            int mid = (l+r)/2;
            if(mtx[mid][0]<=target){
                pr = mid;
                l = mid;
            }
            else{
                r = mid;
            }
        }

        if(pr==-1) return 0;

        l = -1, r = m;

        while(l+1<r){
            int mid = (l+r)/2;
            if(mtx[pr][mid]<target){
                l = mid;
            }
            else if(mtx[pr][mid]>target){
                r = mid;
            }
            else{
                return 1;
            }
        }

        return 0;
        
    }
};
