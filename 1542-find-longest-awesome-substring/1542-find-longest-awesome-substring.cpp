class Solution {
public:
    #define umap unordered_map
    #define uset unordered_set
    #define vi vector<int>
    int longestAwesome(string s) {
        umap <int, int> M;
        int mask = 0, res = 0;
        M[mask] = -1;
        for(int i = 0; i < s.size(); i++){
            mask ^= 1<<(s[i] - '0');
            if(M.find(mask) != M.end()) res = max(res, i - M[mask]);
            for(int j = 0; j <= 9; j++){
                if(M.find(mask^(1<<j)) != M.end()) res = max(res, i - M[mask^(1<<j)]);
            }
            if(M.find(mask) == M.end()) M[mask] = i;
        }
        return res;
    }
};