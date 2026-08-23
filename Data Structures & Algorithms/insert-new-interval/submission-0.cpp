class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& vv, vector<int>& newI) {
        vector<vector<int>> ret;
        int st = INT_MAX,en = INT_MIN;
        bool tbi = 0;
        for(auto v : vv){
            if(v[1]<newI[0] || v[0]>newI[1]){
                ret.push_back(v);
            }
            else {
               st= min({st,newI[0],v[0]});
               en = max({en,newI[1],v[1]});

               if(tbi){
                ret.pop_back();
                ret.push_back({st,en});

               }

               if(!tbi){
                tbi = 1;
                ret.push_back({st,en});
               }
            }
        }

        if(!tbi){
            if(!vv.size()){
                ret.push_back(newI);
                return ret;
            }
            if(newI[1] < vv[0][0]){
                ret.insert(ret.begin(), newI);
                return ret;
            }
            ret.push_back(newI);
            sort(ret.begin(),ret.end());

        }

        return ret;
        
    }
};
