class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // the optimal solution is one that has O(1) space complexity
        // when encountering a 0 we simply set the left endpoint of those rows and column to 0. then update later
        bool firstrow = false, firstcol = false;
        int m = matrix.size(), n = matrix[0].size();

        for(auto j = 0; j < n; j++) {if(matrix[0][j] == 0) firstrow = true;} 
        for(auto i = 0; i < m; i++) {if(matrix[i][0] == 0) firstcol = true;}
        

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
        for(auto i = 1; i < m; i++)
            for(auto j = 1; j < n; j++)
                if(matrix[i][0] == 0 or matrix[0][j] == 0) {matrix[i][j] = 0;}
        
        if(firstrow) for(auto j = 0; j < n; j++) matrix[0][j] = 0;
        if(firstcol) for(auto i = 0; i < m; i++) matrix[i][0] = 0;
    }
};