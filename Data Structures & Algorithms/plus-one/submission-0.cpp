class Solution {
public:
        string add(string a, string b){
        string res="";
        if(a.size()<b.size()) swap(a,b);

        int n = a.size();
        int m = b.size();

        int carry = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        for(int i=0;i<n;i++){
            int curr = a[i]-'0'+ carry ;
            if(i<m) curr +=(b[i]-'0');
            res += ('0' + curr%10);
            carry = curr/10;
        }

        if(carry) res += ('0'+carry);

        reverse(res.begin(),res.end());
        return res;
        
    }

    vector<int> plusOne(vector<int>& digits) {

        string a= "";
        for(auto c : digits) a += ('0' + c);
        a = add(a,"1");
        vector<int> ans;
        for(auto c : a){
            ans.push_back((c-'0'));
        }
        return ans;    
    }
};
