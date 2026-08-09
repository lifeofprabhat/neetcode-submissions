class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        queue<std::pair< int, pair<int,int> > >q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};


        while(!q.empty()){
            auto curr = q.front();
            int curr_d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == INT_MAX){
                    grid[nx][ny] = curr_d + 1;
                    q.push({curr_d+1, {nx,ny}});
                }
            }
        }


        
    }
};
