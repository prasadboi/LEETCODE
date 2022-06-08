class Solution {
public:
    
    #define ll long long int
    #define vll vector<ll>
    #define vi vector<int>
    
    vector<int> findPeakGrid(vector<vector<int>>& matrix) 
    {
        ll m = matrix.size(), n = matrix[0].size();
        ll lo = 0, hi = n-1;
        while (lo <= hi) 
        {
            ll mid = lo + (hi - lo) / 2;
            int max_row = 0;
            
            for (int i = 0; i < m; ++i) 
            {
                if (matrix[max_row][mid] < matrix[i][mid])
                    max_row = i;
            }
            
            if ((mid == 0 or matrix[max_row][mid] > matrix[max_row][mid - 1]) and 
                (mid == n - 1 or matrix[max_row][mid] > matrix[max_row][mid + 1]))
                return {max_row, (int)mid};
            else if (mid > 0 && matrix[max_row][mid - 1] > matrix[max_row][mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return {-1, -1};
    }
};