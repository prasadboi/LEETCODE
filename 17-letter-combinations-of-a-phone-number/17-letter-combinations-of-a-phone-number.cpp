class Solution {
public:
    string D;
    void get_perm(int i, int n, string temp, vector<string> &res, unordered_map<int, string> M)
    {
        // cout<<"i = "<<i<<", temp = "<<temp<<endl;
        if(i == n){
            if(temp.size() > 0) res.push_back(temp); 
            return;
        }
        for(auto c : M[D[i] - '0'])
        {
            temp.push_back(c);
            get_perm(i+1, n, temp, res, M);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        D = digits;
        // if(D == "") return {""};
        unordered_map<int, string> numToChar;
        numToChar[1] = "";
        numToChar[2] = "abc";
        numToChar[3] = "def";
        numToChar[4] = "ghi";
        numToChar[5] = "jkl";
        numToChar[6] = "mno";
        numToChar[7] = "pqrs";
        numToChar[8] = "tuv";
        numToChar[9] = "wxyz";
        numToChar[0] = " ";
        
        vector<string> res;
        string temp;
        int n = digits.size();
        get_perm(0, n, temp, res, numToChar);
        return res;
    }
};