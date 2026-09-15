class Solution {
public:
    bool check(string s){
        string t;
        for(char &c : s){
            if(isupper(c) or islower(c) or isdigit(c) ){
                t+=tolower(c);
            }
        }

        int n = t.size();

        for(int i=0;i<n/2;i++){
            if(t[i] != t[n-1-i]) return 0;
        }

        return 1;
    }
    bool isPalindrome(string s) {
        return check(s);
    }
};
