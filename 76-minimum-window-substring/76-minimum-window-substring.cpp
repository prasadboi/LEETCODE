class Solution {
public:
    #define ll long long int
    #define INF (1e9+7)
    #define vi vector<int>
    #define vvi vector<vector<int>>
    #define umap unordered_map
    
    
    string minWindow(string s, string t) {
        umap<char, int> tfreq;
        for(auto i : t) tfreq[i]++;
        
        int nt = t.size(), ns = s.size();
        
        int l = 0, r = 0, ctr = 0;
        string res = "";
        umap<char, int> sfreq;
        while(l <= r and r < ns)
        {
            // cout<<"curr substring : l = "<<l<<", r = "<<r<<" -> "<<s.substr(l, r - l + 1)<<endl;
            // if the character is there in tfreq and contributes to the minimum sliding substring
            if(tfreq[s[r]] > 0 and sfreq[s[r]] < tfreq[s[r]]){ctr++;}
            sfreq[s[r]]++;
            // cout<<"counter = "<<ctr<<endl;
            // if we have come across all the required characters from t
            while(ctr == nt and l <= r)
            {
                if(ctr == nt)
                {
                    string str = s.substr(l, r - l + 1);
                    // cout<<"substr under consideration : "<<str<<endl;
                    if(res != "") 
                    {
                        if(res.size() > str.size()) res = str;
                        else if(res.size() == str.size()) res = min(res, str);
                    }
                    else res = s.substr(l, r - l + 1);
                }
                sfreq[s[l]]--;
                // if s[l] contributes to the minimum sliding substring
                if(tfreq[s[l]] > 0 and sfreq[s[l]] < tfreq[s[l]]) ctr--;
                l++;
            }
            r++;
        }
        
        return res;
    }
};