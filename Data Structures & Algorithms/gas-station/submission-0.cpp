class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int t_g = 0;
        int t_c = 0;
       
        vector<int> pos;
        for(int i=0;i<n;i++){
            t_g += gas[i];
            t_c += cost[i];
            pos.push_back(gas[i]-cost[i]);
        }

        if(t_c>t_g) return -1;

        int idx = 0;

        int sum = 0;

        for(int i=0;i<n;i++){
            if(sum<0){
                idx = i;
                sum = 0;
            }
            sum+=pos[i];
        }

        return idx;
        
    }
};
