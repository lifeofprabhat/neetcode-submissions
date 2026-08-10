class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& L) {

        set<string> st;

        for(auto str : L) st.insert(str);

        int wL = bw.size();

        set<string>vis;

        queue< pair<int, string> >q;

        q.push({1,bw});
        vis.insert(bw);

        while(!q.empty()){
            auto [curr_d, curr_w] = q.front();
            q.pop();

            for(int i=0;i<wL;i++){
                string tmpW = curr_w;
                for(int j=1;j<26;j++){
                    string tmp = tmpW;
                    tmp[i] = ('a' + (tmp[i]-'a'+j)%26);
                    if(vis.count(tmp)) continue;
                    vis.insert(tmp);
                    if(tmp == ew && st.count(ew)) return curr_d + 1;
                    if(st.count(tmp))
                     q.push({curr_d+1, tmp});
                }
            }
        }

        
       return 0;
        
    }
};
