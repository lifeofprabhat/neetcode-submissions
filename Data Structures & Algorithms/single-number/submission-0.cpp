class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int f = 0;

        for(auto x : nums)
          f^=x;

        return f;
        
    }
};
