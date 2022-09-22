class Solution {
public:
    bool Try(string s, string t)
    {
        string x = t;
        if(s.size()%x.size()) return false;
        for(auto i = 0; i < s.size()/t.size()-1; i++)
        {
            x = x + t;
        }
        // cout<<"x = "<<x<<", s = "<<s<<", s.size()/t.size() = "<<s.size()/t.size()<<endl;;
        return x == s;
    }
    string gcdOfStrings(string s1, string s2) {
        if(s1.size() < s2.size()) return gcdOfStrings(s2, s1);
        string t;
        string res;
        for(auto i : s2)
        {
            t.push_back(i);
            // cout<<"T = "<<t<<endl;
            if(Try(s1, t) == true and Try(s2, t) == true){
                // cout<<"y\n";
                res = t;
            }
        }
        // cout<<"------------------\n";
        return res;
    }
};