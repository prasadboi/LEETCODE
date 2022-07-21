class Solution {
public:
    void genBrackets(int n, int open, int close, string temp, vector<string> &res)
    {
        if(open == n and close == n){
            res.push_back(temp); return;
        }
        if(open < n)
        {
            temp.push_back('(');
            genBrackets(n, open+1, close, temp, res);
            temp.pop_back();
        }
        if(close < n and close < open)
        {
            temp.push_back(')');
            genBrackets(n, open, close+1, temp, res);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> res;
        genBrackets(n, 0, 0, temp, res);
        return res;
    }
};