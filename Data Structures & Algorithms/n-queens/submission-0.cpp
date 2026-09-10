class Solution {
public:
   bool rows[9], cols[9];
   char ar[9][9];
   int invalidPos[9][9];

   void mark(int row, int col, int n, int val){
    int dx[8]={0, 0,1,-1,-1, 1, -1,1};
    int dy[8]={1,-1,0, 0, 1,-1, -1,1};
    invalidPos[row][col] +=val;
    for(int i=0;i<8;i++){
        int currx = row+dx[i], curry = col+dy[i];
        while(currx>=0 && currx<n && curry>=0 && curry<n){
            invalidPos[currx][curry] +=val;
            currx +=dx[i];
            curry +=dy[i];
        }
    }

   }
   vector<vector<string>> ans;
   void dfs(int col,int n){
    if(col==n){
        vector<string> one;
        for(int i=0;i<n;i++){
           string curr = "";
           for(int j=0;j<n;j++){
            curr+=ar[i][j];
           }
           one.push_back(curr); 
        }
        ans.push_back(one); 
        return; 
    }

    for(int i=0;i<n;i++){
        if(!invalidPos[i][col]){
            ar[i][col] ='Q';
            mark(i,col,n,1);
            dfs(col+1,n);
            mark(i,col,n,-1);
            ar[i][col] ='.';
        }
    }

   }
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
              ar[i][j] = '.';
            }
        }
        dfs(0,n);
        return ans;
        
    }
};
