class MinStack {
public:
    stack<long>st;
    long min;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min = val;
        }
        else {
            st.push(val-min);
            if(val<min){
                min=val;
            }
        }
        
    }
    
    void pop() {
        if(st.top()<0){
            min = min - st.top();
        }
        st.pop();  
    }
    
    int top() {
        if(st.top()<0)
          return min;
        return min + st.top();
        
    }
    
    int getMin() {
        return min;
        
    }
};
