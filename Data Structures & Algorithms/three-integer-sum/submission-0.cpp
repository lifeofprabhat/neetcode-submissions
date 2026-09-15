class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if (nums[i] > 0)
                break;

            // Avoid duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    int leftVal = nums[l];
                    int rightVal = nums[r];

                    while (l < r && nums[l] == leftVal)
                        l++;

                    while (l < r && nums[r] == rightVal)
                        r--;

                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return ans;
    }
};