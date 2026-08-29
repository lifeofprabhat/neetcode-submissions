class Solution {
public:
map<int,int> mp;
//num, pos
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0;i<nums.size();i++)
           mp[nums[i]]=i;


        for(int i=0;i<nums.size();i++){
            if(mp.contains(target-nums[i])){
                if(target==2*nums[i]){
                    if(mp[nums[i]] != i){
                        return {i,mp[nums[i]]};
                    }
                }
                else{
                    return {i,mp[target-nums[i]]};
                }
            }
        }

        return {};
        
    }
};
