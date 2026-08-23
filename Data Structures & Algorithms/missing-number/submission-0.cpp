class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum += x;
        int n = nums.size();

        if(n%2){
            return ((n+1)/2)*n - sum;
        }

        return (n+1)*(n/2)-sum;
        
    }
};
