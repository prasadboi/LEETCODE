/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(auto i = 0; i < (n+1)/2; i++)
        {
            for(auto j = 0; j < n/2; j++)
            {
                int temp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(auto i = matrix.begin(); i != matrix.end(); i++) reverse((*i).begin(), (*i).end());
        for(auto i = 0; i <= n; i++)
        {
            for(auto j = 0; j < n - i; j++)
            {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        
    }
};