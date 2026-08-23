class Solution {
public:
    int reverse(int x) {

        int ax = abs(x);
        string sx = to_string(ax);
        ::reverse(sx.begin(), sx.end());
        long z = stoll(sx);

        if(z&(1LL<<31) || z&(1LL<<32) || z&(1LL<<33) || z&(1LL<<34) ) return 0;
        //cout<<z<<endl;
        if(x<0LL) z *=-1LL;
        //cout<<z<<endl;
        return z;
        
    }
};
