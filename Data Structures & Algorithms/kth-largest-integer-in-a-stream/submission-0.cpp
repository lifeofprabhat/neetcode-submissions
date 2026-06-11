class KthLargest {
public:
    priority_queue<int,vector<int> , greater<int> >pq;
    int K ;
    KthLargest(int k, vector<int>& nums) {
       K = k;
       for(auto x : nums) pq.push(x);
       while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
       pq.push(val);
       if(pq.size()>K) pq.pop();
       return pq.top();
    }
};
