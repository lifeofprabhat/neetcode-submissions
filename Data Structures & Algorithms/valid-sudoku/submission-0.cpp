class Solution {
public:

  bool checkBox(vector<vector<char>>& g){
     
     
     for(int x =0;x<9;x+=3){
        for(int y=0;y<9;y+=3){
            set<int> st;
     for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(g[i][j] != '.'){
            if(st.count(g[i][j])) return 0;
            st.insert(g[i][j]);
            }
        }
     }
        }
     }

     return 1;
  }

  bool checkRnC(vector<vector<char>>& g){
    for(int i=0;i<9;i++){
        set<int> stR, stC;
        for(int j=0;j<9;j++){
            if(g[i][j]!='.'){
            if(stR.count(g[i][j])) return 0;
            stR.insert(g[i][j]);
            }
            if(g[j][i] != '.'){
            if(stC.count(g[j][i])) return 0;
            stC.insert(g[j][i]);
            }
        }
    }

        return 1;
  }
    bool isValidSudoku(vector<vector<char>>& g) {

        return checkBox(g) && checkRnC(g);
    }
};
