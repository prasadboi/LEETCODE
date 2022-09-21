class Solution {
public:
    #define umap unordered_map
    #define uset unordered_set
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    
    
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        umap<ll, set<ll>> UAM;
        for(auto i = 0; i < logs.size(); i++)
            UAM[logs[i][0]].insert(logs[i][1]);
        
        vector<int> res(k, 0);
        for(auto i : UAM)
        {
            res[i.second.size() - 1]++;
        }
        return res;
    }
};