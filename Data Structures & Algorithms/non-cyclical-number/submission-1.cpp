class Solution {
public:
    int sumOfD(int n){
        int res = 0;
        while(n){
            int last_d = n%10;
            res += last_d*last_d;
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {

     unordered_set<int> st;
     st.insert(n);
     while(n != 1){
        n = sumOfD(n);
        if(st.contains(n)) return 0;
        st.insert(n);
       
     }

     return 1;
        
    }
};
