class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(auto c : s){
            if(c=='(') st.push(c);
            else{
                if(st.empty()) return 0;
                st.pop();
            }
        }

        return st.empty();
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>  ret;
        for(int i=0;i<(1<<2*n);i++){
            string s;
            for(int j=0;j<2*n;j++){
                if(i&(1<<j)) s +='(';
                else s += ')';
            }
            if(isValid(s)) ret.push_back(s);
        }
        return ret;
        
    }
};
