class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {

        vector<int> freq(1005,0);

        for(auto x : hand)
          freq[x]++;

        if(hand.size()%k) return 0;

        for(int i=0;i<=1000-k+1;i++){
            while(freq[i]){

             for(int j=i;j<i+k;j++){
                if(freq[j]) freq[j]--;
                else return 0;
             }

            }

        }

        return 1;

        
    }
};
