class Solution {
public:
    unordered_map<char, int> val;
    
    void mapValues()
    {
        val['I'] = 1, val['V'] = 5, val['X'] = 10, val['L'] = 50, val['C'] = 100,
        val['D'] = 500, val['M'] = 1000;
    }
    
    int romanToInt(string s) 
    {
        mapValues();
        int curr = 0;
        int res = 0;
        for(auto i : s){
            if(curr < val[i]) res += (val[i]-2*curr);
            else res += val[i];
            curr = val[i];
        }
        return res;
    }
};