class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 1 or x == 0) return x;
        double l = 0, r = x;
        while(l <= r)
        {
            long long int m = l + (r-l)/2;
            if(m*m <= x and (m+1)*(m+1) > x) return m;
            else if(m*m > x) r = m-1;
            else l = m+1;
        }
        return -1;
    }
};