class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return (myPow(1/x, abs(n)));
        if(n == 0) return 1;
        
        long double val = myPow(x, n/2);
        if(n%2) return val*val*x;
        else return val*val;
    }
};