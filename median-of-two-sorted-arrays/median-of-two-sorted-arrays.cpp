class Solution {
public:
    #define ll long long int
    #define vd vector<double>
    #define vi vector<int>
    #define INF (1e9 + 7)
    #define NEG_INF (-1*(1e9 + 7))
    
    double findMedianSortedArrays(vector<int> X, vector<int>& Y) 
    {
        if(X.size() > Y.size()) return findMedianSortedArrays(Y, X);
        
        int nx = X.size(), ny = Y.size(), midlen = ceil((double)(nx + ny)/2);
        int lo = 0, hi = X.size();
        while(lo <= hi)
        {
            int mx = lo + (hi - lo)/2; // the midpoint of array X under cosideration
            // the length of array Y split such that 
            // X_L.size() + Y_L.size() == X_R.size() + Y_R.size()
            int y = midlen - mx; 

            double maxLeftX = (mx == 0) ? INT_MIN : X[mx - 1];
            double minRightX = (mx == nx) ? INT_MAX : X[mx];
            
            double maxLeftY = (y == 0) ? INT_MIN : Y[y-1];
            double minRightY = (y == ny) ? INT_MAX : Y[y];

            // median is possible when : 
            if(maxLeftX <= minRightY and maxLeftY <= minRightX)
            {
                if((nx + ny)%2) return max(maxLeftX, maxLeftY);
                else return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
            }
            // median lies to the left of the current mx
            else if(maxLeftX > minRightY) hi = mx-1;
            // median lies to the right of the current mx
            else lo = mx + 1;
        }
        return 0;
    }
};