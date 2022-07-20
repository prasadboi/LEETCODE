class Solution {
public:
    #define vi vector<int>
    #define umap unordered_map
    #define uset unordered_set
    int findTheLongestSubstring(string s) {
        // if the number of characters is odd, increment ctr by 1 else decremetn ctr by 1
        uset<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        umap<int, int> M; // stores the earliest index with a particular count
        int mask = 0, res = 0;
        M[mask] = -1;
        for(auto i = 0; i < s.size(); i++)
        {
            if(vowels.find(s[i]) != vowels.end()) mask ^= s[i]; 
            if(M.find(mask) != M.end()) res = max(res, i - M[mask]);
            else M[mask] = i;
        }
        return res;
    }
};