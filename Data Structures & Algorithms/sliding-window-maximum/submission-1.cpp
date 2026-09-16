class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mp;
       
        vector<int> ans;
        set<int>st;

        for(int i=0;i<k;i++)
        {
            st.insert(nums[i]);
            mp[nums[i]]++;
        }

        ans.push_back(*st.rbegin());

        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                st.erase(nums[i-k]);
                //cout<<"pk"<<endl;
            }
            mp[nums[i]]++;
            st.insert(nums[i]);
            ans.push_back(*st.rbegin());

        }

        return ans;
        
    }
};
