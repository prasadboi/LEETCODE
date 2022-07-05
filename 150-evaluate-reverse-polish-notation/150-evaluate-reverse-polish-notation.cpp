class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define ll long long int
    #define vstr vector<string>
    unordered_map<string, bool> op;
    void make_map()
    {
        op["*"] = true;
        op["/"] = true;
        op["-"] = true;
        op["+"] = true;
    }
    int evalRPN(vector<string>& tokens) 
    {
        make_map();
        int res = 0;
        stack<string> postfix;
        for(auto i : tokens){
            if(op.find(i) != op.end()) 
            {
                res = stoi(postfix.top()); postfix.pop();
                if(i == "*"){res = res*stoi(postfix.top()); postfix.pop();}
                else if(i == "/"){res = stoi(postfix.top())/res; postfix.pop();}
                else if(i == "-"){res = stoi(postfix.top()) - res; postfix.pop();}
                else if(i == "+"){res = stoi(postfix.top()) + res; postfix.pop();}
                postfix.push(to_string(res));    
            }
            else
            {
                postfix.push(i);
            }
        }
        if(postfix.size() == 0)return res; else return stoi(postfix.top());
    }
};