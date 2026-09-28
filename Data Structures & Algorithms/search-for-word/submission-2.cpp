class Solution {
public:

   vector<vector<bool>>vis;
   int N,M;
   string target;

   int dx[4] = {0,0, 1, -1};
   int dy[4] = {1, -1,0, 0};

   bool dfs(vector<vector<char>>& board, int x, int y, int pos){
     if(pos == target.size()-1) return 1;

     vis[x][y] = 1;

     for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        cout<<nx<<" "<<ny<<endl;

        if(nx>=0 and nx <N and ny>=0 and ny<M and !vis[nx][ny] ){
            if((board[nx][ny] == target[pos+1] && dfs(board, nx, ny, pos+1))) {cout<<"found"<<endl; return true;}
        }
     }

     vis[x][y] = 0;

     return false;

   }

    bool exist(vector<vector<char>>& board, string word) {
         N = board.size();
         M = board[0].size();
         target = word;
         vis.resize(N+1, vector<bool>(M+1, false));

         for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,0) || target.size()==1) return true;
                }
            }
         }

         return false;
        
    }
};
