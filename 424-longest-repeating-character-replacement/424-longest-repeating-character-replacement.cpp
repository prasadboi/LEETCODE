class Solution {
public:
    #define umap unordered_map
    int characterReplacement(string s, int k) {
        int res = 0, l = 0, r = 0, n = s.size();
        umap<char, int> freq;
        int  maxFreq = 0;
        for(; r < n; r++)
        {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while((r - l + 1) - maxFreq > k)
                freq[s[l]]--, l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};