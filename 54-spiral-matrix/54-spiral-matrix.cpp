class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int u = 0,d = m-1, l = 0, r = n-1;
        vector<int> res;
        while(u <= d and l <= r)
        {
            for(int i = l; i <= r; i++) res.push_back(matrix[u][i]); u++;
            for(int i = u; i <= d; i++) res.push_back(matrix[i][r]); r--;
            for(int i = r; i >= l; i--) res.push_back(matrix[d][i]); d--;
            for(int i = d; i >= u; i--) res.push_back(matrix[i][l]); l++;
        }
        while(res.size() > m*n) res.pop_back();
        return res;
    }
};