class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define ll long long int
    #define pll pair<ll, ll>
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        auto cmp = [](const vi &a, const vi &b){return ((a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]));};
        set<pll> dist;
        for(int i = 0; i < points.size(); i++){
            dist.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        vvi res;
        for(int i = 0; i < k and dist.size(); i++){
            res.push_back(points[dist.begin()->second]);
            dist.erase(dist.begin());
        }
        return res;
    }
};