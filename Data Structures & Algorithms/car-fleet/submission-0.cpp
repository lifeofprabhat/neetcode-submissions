class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {

        vector< pair<int,int> > ar;
        for(int i=0;i<pos.size();i++){
            ar.push_back({pos[i],sp[i]});
        }

        sort(ar.begin(), ar.end());
        reverse(ar.begin(),ar.end());

        stack<double> st;

        for(int i=0;i<pos.size();i++){
            double remD = target-ar[i].first;
            double tt = remD/ar[i].second;

            if(st.empty()){
                st.push(tt);
            }
            else{
                if(tt>st.top())
                  st.push(tt);
            }
        }

        return st.size();
        
        
    }
};
