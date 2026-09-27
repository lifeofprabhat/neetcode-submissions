class Solution {
public:
    vector<int> nextP(vector<int>& inP){
        int N = inP.size();
        priority_queue<int /*, vector<int>, greater<int> */>pq;

        for(int i = N-1;i>=0; i--){
            if(pq.empty()){
                pq.push(inP[i]);
                continue;
            }
            if(pq.top()<inP[i]){
                pq.push(inP[i]);
            }
            else{
                int curr = pq.top();
                pq.pop();
                int tmp = inP[i];
                pq.push(inP[i]);
                inP[i] =  curr;

                for(int j = N-1;j>i;j--){
                    inP[j] = pq.top();
                    if(inP[j]>tmp){
                        swap(inP[j],inP[i]);
                    }
                    pq.pop();
                }
                break;
            }
        }

        return inP;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int tot = 1;
        int cnt =2;
        while(cnt<=nums.size()){
            tot*=cnt;
            cnt++;
        }
        ans.push_back(nums);
        vector<int> next = nums;
        for(int i=2;i<=tot;i++){
            next = nextP(next);
            ans.push_back(next);
        }
        return ans;
    }
};
