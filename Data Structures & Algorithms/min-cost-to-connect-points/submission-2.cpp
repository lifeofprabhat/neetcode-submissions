class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {

        if (pts.size() < 2)
            return 0;

        set<pair<int,int>> st;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {pts[0][0], pts[0][1]}});

        int ans = 0;

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int curr_d = top.first;
            int x = top.second.first;
            int y = top.second.second;

            // Important: ignore stale entries
            if (st.contains({x, y}))
                continue;

            ans += curr_d;
            st.insert({x, y});

            for (int i = 0; i < pts.size(); i++) {

                if (st.contains({pts[i][0], pts[i][1]}))
                    continue;

                int next_d =
                    abs(pts[i][0] - x) +
                    abs(pts[i][1] - y);

                pq.push({
                    next_d,
                    {pts[i][0], pts[i][1]}
                });
            }
        }

        return ans;
    }
};