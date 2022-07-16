class Solution {
public:
    bool rowsValid(vector<vector<char>> &board)
    {
        for(auto i = 0; i < 9; i++)
        {
            int row = 0;
            for(auto j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                if((row & 1<<(board[i][j] - '0')) == (1<<(board[i][j] - '0'))) return false;
                else row = row|(1<<(board[i][j] - '0'));
            }
        }
        return true;
    }
    
    bool colsValid(vector<vector<char>> &board)
    {
        for(auto j = 0; j < 9; j++)
        {
            int col = 0;
            for(auto i = 0; i < 9; i++)
            {
                if(board[i][j] == '.') continue;
                if((col & (1<<(board[i][j] - '0'))) == (1<<(board[i][j] - '0'))) return false;
                else col = col | (1<<(board[i][j] - '0'));
            }
        }
        return true;
    }
    
    bool boxValid(vector<vector<char>> &board)
    {
        for(auto row = 0; row < 9; row += 3)
        {
            for(auto col = 0; col < 9; col += 3)
            {
                int box = 0;
                for(auto i = 0; i < 3; i++)
                {
                    for(auto j = 0; j < 3; j++)
                    {
                        int x = i + row, y = j + col;
                        if(board[x][y] == '.') continue;
                        if((box & (1<<(board[x][y] - '0'))) == (1<<(board[x][y] - '0'))) return false;
                        else box = box|(1<<(board[x][y] - '0'));
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        return rowsValid(board) and colsValid(board) and boxValid(board);
    }
};