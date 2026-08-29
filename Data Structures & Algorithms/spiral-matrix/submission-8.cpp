#include<bits/stdc++.h>
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int vis[11][11];
    int N,M;
    int cnt =0;
    vector<vector<int>> MTX;
    
    bool ok(int x, int y){
        if(x<0 || x>=N || y<0 || y>=M || vis[x][y]) return 0;
        return 1;
    }
    void dfs(int x, int y, int dir,vector<int>&ans){

        if(!vis[x][y]){
           cnt++;
           vis[x][y]=1;
           ans.push_back(MTX[x][y]);
           if(cnt==N*M) return;
        }
        

        for(int i=0;i<4;i++){
            int nx = x + dx[(dir+i)%4];
            int ny = y + dy[(dir+i)%4];
            if(ok(nx,ny))
            {
                dfs(nx,ny,(dir+i)%4,ans);
                break;
            }
        }
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        MTX = matrix;
        N = matrix.size();
        M = matrix[0].size();
        memset(vis,0,sizeof(vis));
        vector<int>ans;
        dfs(0,0,0,ans); //cout<<"WHY"<<endl;
        return ans;     
    }
};
