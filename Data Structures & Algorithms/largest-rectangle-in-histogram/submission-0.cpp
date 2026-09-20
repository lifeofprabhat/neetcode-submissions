class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {

        stack<int> st;
        int ans = hts[0];
        int n = hts.size();
        
        vector<int> pref(n,0);

        for(int i=0;i<hts.size();i++){
            while(!st.empty() && hts[st.top()]>=hts[i])
              st.pop();

            if(st.empty()) pref[i] = 0;
            else pref[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int>suff(n,0);

        for(int i=n-1;i>=0;i--){
             while(!st.empty() && hts[st.top()]>=hts[i])
              st.pop();

            if(st.empty()) suff[i] = n-1;
            else suff[i] = st.top() - 1; 
            st.push(i);

        }

        for(int i=0;i<hts.size();i++){
            ans = max(ans, hts[i]*(suff[i]-pref[i]+1));
        }

        return ans;
        
    }
};
