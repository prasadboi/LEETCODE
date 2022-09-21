class Solution {
public:
    #define umap unordered_map
    #define uset unordered_set
    #define ll long long int
    #define vll vector<ll>
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // count number of substrings with 
        // max unique letters  = maxLetters
        // minSize = minSize
        // maxSize = maxSize
        
        // key idea : the most frequent string will always be of size minSize
        // reason : if there exists a string of maxFreq with size larger than the minSize, then there will always be any substring of size == minSize with the same frequency :0
        umap<char, int> letters;
        map<string, int> string_freq;
        int res = 0;
        int count = 0;
        
        for(auto i = 0; i < minSize; i++) letters[s[i]]++;
        if(letters.size() <= maxLetters){
            string x = s.substr(0, minSize);
            string_freq[x]++;
        }
        
        int l = 1, r = l + minSize - 1;
        for(; r < s.size();)
        {
            letters[s[r]]++;
            letters[s[l-1]]--;
            if(letters[s[l-1]] == 0) letters.erase(s[l-1]);
            if(letters.size() <= maxLetters)
            {
                string x = s.substr(l, r - l + 1);
                string_freq[x]++;
                res = max(res, string_freq[x]);
            }
            l++, r++;
        }
        return res;
    }
};