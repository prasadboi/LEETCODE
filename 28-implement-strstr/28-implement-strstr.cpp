class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle == "") return 0;
        int n_size = needle.size();
        int l = 0, r = n_size-1;
        while(r < haystack.size())
        {
            if(haystack.substr(l, n_size) == needle) return l;
            else l++, r++;
        }
        return -1;
    }
};