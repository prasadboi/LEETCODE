class Solution {
public:
    #define vi vector<int>
    #define umap unordered_map
    #define uset unordered_set
    int findTheLongestSubstring(string s) {
        uset<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        umap<int, int> M; // stores the earliest index with a particular mask
        // in 545 : we need equal numberof 0s and 1s
        // here : we need EVEN number of vowels of a kind. Therefore we can use a mask
        int mask = 0, res = 0;
        M[mask] = -1;
        for(auto i = 0; i < s.size(); i++)
        {
            if(vowels.find(s[i]) != vowels.end()) mask ^= 1<<(s[i] - 'a');
            if(M.find(mask) != M.end()) res = max(res, i - M[mask]);
            else M[mask] = i;
        }
        return res;
    }
};