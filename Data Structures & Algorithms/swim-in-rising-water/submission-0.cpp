class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        

        set<pair<int,int>> st;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({grid[0][0], {0,0}});

        int ans = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int n = grid.size();
        int m = grid[0].size();

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int curr_d = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if(x==n-1 && y == m-1) return curr_d;

            // Important: ignore stale entries
            if (st.contains({x, y}))
                continue;

            ans += curr_d;
            st.insert({x, y});

            for (int i = 0; i < 4; i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx< 0 || nx >=n || ny<0 || ny>=m) continue;

                if (st.contains({nx,ny}))
                    continue;
                
                int next_d = max(curr_d, grid[nx][ny]);
            
                pq.push({
                    next_d,
                    {nx, ny}
                });
            }
        }

        return ans;
        
    }
};
