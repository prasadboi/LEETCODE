class Solution {
public:
    #define umap unordered_map
    int characterReplacement(string s, int k) {
        int res = 0, l = 0, r = 0, n = s.size();
        umap<char, int> freq;
        // for a given window the window size >= (k + the max freq char in that window)
        for(; r < n; r++)
        {
            freq[s[r]]++;
            int maxFreq = 0;
            for(auto i : freq) maxFreq = max(maxFreq, i.second); // stores the max freq of the char in that window
            // you could also keep track of the max freq char by 
            // iterating over the ffreq hashmap and finding the max freq char for the window
            while((r - l + 1) - maxFreq > k)
                freq[s[l]]--, l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};