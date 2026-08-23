class Solution {
public:
    string mul(string a, int b){
        string res="";

        int n = a.size();
        int carry = 0;
        reverse(a.begin(),a.end());

        for(int i=0;i<a.size();i++){
            int curr = b*(a[i]-'0')+carry;
            res+=('0' + (curr%10));
            carry = curr/10;
        }

        if(carry) res += ('0'+carry);

        reverse(res.begin(), res.end());

        return res;
    }

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
    string multiply(string num1, string num2) {

        string res = "";
        string suff= "";

        if(num2.size()<2 && stoi(num2)==0) return "0";

        for(int i=num2.size()-1;i>=0;i--){
            string curr = mul(num1,num2[i]-'0');
            curr += suff;
            res = add(res,curr);
            suff += '0';
        }

        return res;
        
    }
};
