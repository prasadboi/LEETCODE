class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if(s.size() == 0 or k == 0) return 0;
        unordered_map<char, int> count;
        int l, r, res = 1;
        for(l = 0, r = 0; r < s.size(); r++)
        {
            count[s[r]]++;
            if(count.size() > k){
                if(--count[s[l]] == 0) count.erase(s[l]);
                l++;
            }
            if(count.size() <= k) res = max(res, r - l + 1);
        }
        return res;
    }
};