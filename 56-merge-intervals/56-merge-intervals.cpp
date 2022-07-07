class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define INF (1e9+7)
    
    static bool cmp(vi &a, vi &b){return a[0] < b[0];}
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vvi res;
        int start = intervals[0][0], end = intervals[0][1];
        for(auto i = 1; i < intervals.size(); i++)
        {
            if(end >= intervals[i][0]) end = max(end, intervals[i][1]);
            else{
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};