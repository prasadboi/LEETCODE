class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define umap unordered_map
    #define uset unordered_set
    #define pq priority_queue
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vll &a, vll &b){return a[2] > b[2];};
        pq<vll, vector<vll>, decltype(cmp)> mindist(cmp); 
        for(auto i : points)
            mindist.push({i[0], i[1], i[0]*i[0] + i[1]*i[1]});
        
        vector<vector<int>> res;
        while(mindist.size() and k--){
            vll x = mindist.top(); mindist.pop();
            res.push_back({(int)x[0], (int)x[1]});
        }
        return res;
    }
};