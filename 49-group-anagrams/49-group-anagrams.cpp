class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // keep every string along with its sorted version
        unordered_map<string, vector<string>> m;
        for(auto i : strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());
            if(m.find(temp) == m.end()) m[temp] = {i};
            else m[temp].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i : m)
        {
            res.push_back(i.second);
        }
        return res;
    }
};