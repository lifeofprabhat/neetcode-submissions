class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> st;
        vector<int> ans;
        int n = T.size();

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({T[i],i});
                ans.push_back(0);
                continue;
            }
            while( !st.empty() && st.top().first<=T[i] ){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
                st.push({T[i],i});
            }
            else{
                ans.push_back(st.top().second-i);
                st.push({T[i],i});
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};
