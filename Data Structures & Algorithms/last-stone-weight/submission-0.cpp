class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> pq;
      for(const auto x : stones){
        pq.push(x);
      }
      while(pq.size()>1){
        auto x = pq.top();
        pq.pop();
        auto y = pq.top();
        pq.pop();
        if(x!=y)
           pq.push(x-y);
      }

      if(pq.size()) return pq.top();
      return 0;

    }
};
