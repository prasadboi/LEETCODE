class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = 0;
        for(auto i : s) if(i != ' ' and i != '-') n++;
        int grps = n/k, firstgrp = n%k;
        cout<<"grps : "<<grps<<", first : "<<firstgrp<<endl;
        string res;
        int i;
        for(i = 0; i < s.size() and firstgrp >= 1; i++)
            if(s[i] != '-'){res.push_back(toupper(s[i])); firstgrp--;}
        if(n%k) res.push_back('-');
        while(i < s.size())
        {
            for(int j = 0; j < k and i < s.size(); )
            {
                if(s[i] != '-'){res.push_back(toupper(s[i])); j++;}
                i++;
            }
            res.push_back('-');
        }
        while(res.size() and !isalnum(res.back())) res.pop_back();
        return res;
    }
};