class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intV, vector<int>& q) {
        vector<pair<int,int>> vq;

        for(int i=0;i<q.size();i++){
            vq.push_back({q[i],i});
        }

        sort(vq.begin(),vq.end());

        int m = q.size();
        int n = intV.size();

        vector<int>ans(m,-1);

        auto cmp =[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]>b[0];
        };

        sort(intV.begin(), intV.end());

        

        priority_queue< 
        vector<int>,
        vector<vector<int>>,
        decltype(cmp)
        >pq;

        int i = 0;

        for(int j =0;j<m;j++){
            while(i<intV.size() && intV[i][0]<=vq[j].first){
                int l = intV[i][0];
                int r = intV[i][1];
                pq.push({r-l+1,r});
                i++;
            }

            while(!pq.empty() && pq.top()[1]<vq[j].first){
                pq.pop();
            }

            if(!pq.empty()){
                ans[vq[j].second] = pq.top()[0];
            }

        }

        return ans;
        
    }
};
