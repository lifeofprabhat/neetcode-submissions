class Solution {
public:
   bool isAOpr(string s){
     return (s=="+" || s=="-" || s=="*" || s=="/");
   }
    int evalRPN(vector<string>& tokens) {
      stack<int>st;
      for(string tok : tokens){
         if(isAOpr(tok)){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if(tok=="+"){
                st.push(a+b);
            }
            else if(tok=="-"){
                st.push(b-a);
            }
            else if(tok=="*"){
                st.push(a*b);
            }
            else{
                st.push(b/a);
            }
         }
         else
           st.push(stoi(tok));
           //cout<<st.top()<<" ";
      }

      return st.top();
        
    }
};
