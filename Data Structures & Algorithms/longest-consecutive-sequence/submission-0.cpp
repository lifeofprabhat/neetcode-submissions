class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2) return nums.size();

        int curr= nums[0], mx=1, currMax=1;;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == curr) continue;
            else if(nums[i] == curr + 1 ){
                currMax++;
                curr = nums[i];
                mx=max(mx,currMax);
            }
            else{
                curr = nums[i];
                currMax=1;
            }
        }

        return mx;
        
    }
};
