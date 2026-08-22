class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& A) {

    vector<vector<int>> fin;
    bool a,b,c; a=b=c=0;
    

    for(auto v : triplets){
        bool any_g = 0;
        bool all_s = 0;

        if(v[0]==A[0] && v[1]==A[1] && v[2]==A[2]) return 1;

        if(v[0]>A[0] || v[1]>A[1] || v[2]>A[2])
           any_g = 1;

        if(v[0]<A[0] && v[1]<A[1] && v[2]<A[2])
          all_s = 1;

        if(any_g || all_s){
            continue;
        }

        if(v[0]==A[0]) a =1;
        if(v[1]==A[1]) b = 1;
        if(v[2]==A[2]) c = 1;
    }

    return a&&b&&c;
        
    }
};
