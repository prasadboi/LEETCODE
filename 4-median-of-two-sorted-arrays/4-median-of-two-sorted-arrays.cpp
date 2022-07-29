class Solution {
public:
    #define ll long long int
    #define vd vector<double>
    #define vi vector<int>
    #define INF (1e9 + 7)
    #define NEG_INF (-1*(1e9 + 7))
    
    double findMedianSortedArrays(vector<int> X, vector<int>& Y) 
    {
        ll nx = X.size(), ny = Y.size(), midLen = ceil((double)(nx + ny)/2);
        if(nx > ny) return findMedianSortedArrays(Y, X);
        ll lo = 0, hi = nx;
        while(lo <= hi)
        {
            // say we want to split the 2 arrays such that there are equal number of numbers on both sides
            // therfore mx + my = midLen;
            ll mx = lo + (hi - lo)/2;
            ll my = midLen - mx;
            
            // now there are 4 numbers to consider
            double X_lmax = (mx == 0) ? INT_MIN : X[mx-1], X_rmin = (mx == nx) ? INT_MAX : X[mx];
            double Y_lmax = (my == 0) ? INT_MIN : Y[my-1], Y_rmin = (my == ny) ? INT_MAX : Y[my];
            
            
            if(X_lmax <= Y_rmin and Y_lmax <= X_rmin){
                // median lies between these 4 numbers
                if((nx + ny)%2) return (double) max(X_lmax, Y_lmax);
                else return (double)(max(X_lmax, Y_lmax) + min(X_rmin, Y_rmin))/2;
            }           
            else if(X_lmax > Y_rmin) // median lies to the left of m
                hi = mx-1;
            // median lies to the right of m
            else lo = mx+1;
        }
        return 0;
    }
};