class Solution {
public:
    int calculate(string s) {
        vector<int> signs(2, 1);
        int total = 0;
        for(auto i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(s[i] >= '0'){
                int num = 0;
                while(i < s.size() and s[i] >= '0'){num = 10*num + (s[i] - '0'); i++;}
                
                total += signs.back()*num;
                signs.pop_back();
                i--;
            }
            else if(c == ')') signs.pop_back();
            else if(c != ' ') signs.push_back(signs.back()*(c=='-' ? -1 : 1));
        }
        return total;
    }
};