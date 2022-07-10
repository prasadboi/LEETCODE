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
            cout<<"u = "<<u<<endl;
            for(int i = u; i <= d; i++) res.push_back(matrix[i][r]); r--;
            cout<<"r = "<<r<<endl;
            for(int i = r; i >= l; i--) res.push_back(matrix[d][i]); d--;
            cout<<"d = "<<d<<endl;
            for(int i = d; i >= u; i--) res.push_back(matrix[i][l]); l++;
            cout<<"l = "<<l<<endl;
        }
        while(res.size() > m*n) res.pop_back();
        return res;
    }
};