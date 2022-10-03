class Solution {
public:
  //binary exponentiation
    double power(double x, int n){
        if(n==0)return 1;
      
        double d=power(x,n/2);
        if(n&1)return x*d*d;
        return d*d;
    }
    double myPow(double x, int n) {
        
      if(n>0){return power(x,n);}
        return 1/power(x,n);//a^-1=1/a
    }
};
