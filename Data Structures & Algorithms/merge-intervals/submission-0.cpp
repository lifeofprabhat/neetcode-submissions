class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intV) {
        sort(intV.begin(), intV.end());
      
      vector<vector<int>> res;
      
      int n = intV.size();

      res.push_back(intV[0]);

      for(int i =1;i<n;i++){
        auto curr = res.back();
        if(curr[1]<intV[i][0]){
            res.push_back(intV[i]);
        }
        else{
            auto curr = res.back();
            res.pop_back();
            curr[1]=max(curr[1],intV[i][1]);
            res.push_back(curr);
        }
        
      }

      return res;

        
    }
};
