class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        map<char,int> mp;
        for(auto c : tasks) mp[c]++;
        
        vector<pair<int,char>>v;
        for(auto [c,f] : mp){
            v.push_back({f,c});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int processedCnt = 0, currIdx = 0;
        int n = tasks.size();

        vector<int> lastIdx(26,-1);
        while(processedCnt<n){
             sort(v.begin(),v.end());
             reverse(v.begin(),v.end());
            char cc = '0';
            for(auto& [f , c] : v){
                if( mp[c] && (lastIdx[c-'A'] == -1 || (currIdx-lastIdx[c-'A']) > k) ){
                    processedCnt++;
                    mp[c]--;
                    lastIdx[c-'A'] = currIdx;
                    cc = c;
                    f--;
                    
                    break;
                    

                }
            }
            currIdx++;
            cout<<currIdx<< " "<<cc<<endl;

        }
       
        return currIdx;
    
        
    }
};
