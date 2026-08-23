class Solution {
public:
    void setZeroes(vector<vector<int>>& mtx) {
        bool zero_in_first_row = 0;
        bool zero_in_first_col = 0;

        int n = mtx.size();
        int m = mtx[0].size();

        for(int i=0;i<n;i++)
          if(mtx[i][0]==0) zero_in_first_col = 1;

        for(int i=0;i<m;i++)
          if(mtx[0][i]==0) zero_in_first_row = 1;

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!mtx[i][j]){
                    mtx[i][0] = 0;
                    mtx[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mtx[i][0]==0 || mtx[0][j]==0)
                  mtx[i][j] = 0;
            }
        }

        if(zero_in_first_row){
            for(int i=0;i<m;i++)
              mtx[0][i] = 0;
        }

        if(zero_in_first_col){
            for(int i=0;i<n;i++)
               mtx[i][0] = 0;
        }
        
    }
};
