class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char, int> freqp;
        for(auto i : p) freqp[i]++;
        
        int l = 0, r = 0;
        vector<int> res;
        while(l <= r and r < n)
        {
            if(--freqp[s[r]] == 0){freqp.erase(s[r]);}
            // have to check whether key is in map before doing freq[key] < 0
            // else key gets auto added into the map with val 0
            if(freqp.find(s[r]) != freqp.end() and freqp[s[r]] < 0){
                while(freqp[s[r]] < 0 and l <= r){freqp[s[l]]++; l++;}
                if(freqp[s[r]] == 0) freqp.erase(s[r]);
            }
            if(freqp.size() == 0){res.push_back(l); freqp[s[l]]++; l++;}
            r++;
        }
        return res;
    }
};