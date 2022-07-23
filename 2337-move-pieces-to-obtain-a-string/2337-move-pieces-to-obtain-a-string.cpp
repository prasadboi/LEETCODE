class Solution {
public:
    bool canChange(string s, string t) {
        if(s.size() != t.size()) return false;
        int sidx = 0, tidx = 0, n = s.size();
        while(true){
            while(sidx < n and s[sidx] == '_') sidx++;
            while(tidx < n and t[tidx] == '_') tidx++;
            
            // cout<<"sidx = "<<sidx<<", tidx = "<<tidx<<endl;
            if(sidx == n and tidx == n) break;
            if(sidx == n or tidx == n) return false;
            
            if(s[sidx] != t[tidx]) return false;
            if(s[sidx] == 'L' and sidx < tidx) return false;
            if(s[sidx] == 'R' and sidx > tidx) return false;
            sidx++, tidx++;
        }
        return true;
    }
};