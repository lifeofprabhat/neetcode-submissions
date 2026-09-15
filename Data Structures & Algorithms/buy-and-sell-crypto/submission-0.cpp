class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minP=prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            profit = max(profit, prices[i]-minP);
            minP = min(minP, prices[i]);
        }
        return profit;
        
    }
};
