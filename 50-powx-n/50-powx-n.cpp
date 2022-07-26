class Solution {
public:
    #define ll long long int
    double myPow(double x, int num) {
        long double res = 1;
        ll n = num;
        if(x == 1) return 1;
        if(n < 0) x = 1/x;
        (n < 0) ? (n = -1*n) : n = n;
        cout<<"x = "<<x<<", n = "<<n<<endl;
        while(n){
            if(n&1) res *= x;
            n = n>>1;
            x = x*x;
        }
        
        return (double)(res);
    }
};