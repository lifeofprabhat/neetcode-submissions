class MedianFinder {
        priority_queue<int> pq;
        priority_queue<int, vector<int> , greater<int> >min_pq;
public:
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        pq.push(num);
        
        if(pq.size()== min_pq.size() + 2){
        int tmp = pq.top();
        pq.pop();
        min_pq.push(tmp);
        }
        else if(min_pq.size() && pq.top()>min_pq.top()){
            int x = pq.top();
            int y = min_pq.top();
            pq.pop();
            min_pq.pop();
            min_pq.push(x);
            pq.push(y);
        }
        
    }
    
    double findMedian() {
        if(pq.size()== min_pq.size())
         return((double)(pq.top() + min_pq.top()))/2.0;

        return pq.top();
        
    }
};
