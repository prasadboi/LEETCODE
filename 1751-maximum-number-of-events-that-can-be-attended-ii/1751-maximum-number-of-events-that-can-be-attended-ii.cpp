class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        auto cmp = [](vi &a, vi &b){return a[0] < b[0];};
        sort(events.begin(), events.end(), cmp);
        
        vector<ll> stTimes;
        for(auto i = 0; i < events.size(); i++) stTimes.push_back(events[i][0]);
        
        ll n = events.size();
        vector<vector<ll>> dp(n+1, vector<ll> (k+1, 0));
        ll res = 0;
        for(auto i = n-1; i >= 0; i--)
        {
            for(auto j = k-1; j >= 0; j--)
            {
                ll res1 = events[i][2];
                auto it = upper_bound(stTimes.begin(), stTimes.end(), events[i][1]);
                if(it != stTimes.end()) res1 += dp[(it - stTimes.begin())][j+1];
                
                ll res2 = dp[i+1][j];
                
                dp[i][j] = max(res1, res2);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};