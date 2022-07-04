class Solution {
public:
    #define ll long long int
    #define INF (1e9 + 7)
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define umapi_i unordered_map<int, int>
    #define umapll_ll unordered_map<ll, ll>
    
    unordered_map<ll, bool> dp_mem;
    bool top_down(ll i, string &s, vector<string> &words){
        if(i == -1) return true;
        if(dp_mem.find(i) != dp_mem.end()) return dp_mem[i];
        bool res = false;
        for(auto word : words){
            string temp = "";
            if(word.size() <= i + 1) temp = s.substr(i - word.size() + 1, word.size());
            if(temp == word) res = res or top_down(i - word.size(), s, words);
        }
        return dp_mem[i] = res;
    }
    
    bool wordBreak(string s, vector<string>& words){
        return top_down(s.size() - 1, s, words);
    }
};