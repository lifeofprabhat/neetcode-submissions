class Solution {
public:
  
    double pow(double x, int n){
        double res  = 1;
        double curr = x;
        while(n){
            if(n%2) res *= curr;
            n/=2;
            curr= curr*curr;
        }

        return res;

    }
    double myPow(double x, int n) {

          if(n==0) return 1;
          
          if(x==0) return 0;

          double val = pow(x,abs(n));

          if(n<0) return 1/val;

          return val;


    }
};
