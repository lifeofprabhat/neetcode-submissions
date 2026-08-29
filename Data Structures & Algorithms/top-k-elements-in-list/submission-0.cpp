class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto x : nums)
          mp[x]++;

        priority_queue< pair<int,int> >pq;
        
        for(auto [num,freq] : mp){
            pq.push({-freq,num});
            if(pq.size()>k)
             pq.pop();
        }

        vector<int>ret;

        while(pq.size()){
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
        
    }
};
