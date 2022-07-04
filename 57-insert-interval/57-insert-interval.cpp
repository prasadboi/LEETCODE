class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define ll long long int
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ll n = intervals.size();
        // get idxs of element bfr and after the newInterval
        ll first_nxt = 0;
        while(first_nxt < n and intervals[first_nxt][0] <= newInterval[1]) first_nxt++;
        ll first_prev = first_nxt-1;
        while(first_prev >=0 and intervals[first_prev][1] >= newInterval[0]) first_prev--;
                
        // calculate the limits of the merged interval
        if(first_nxt-1 >= 0)newInterval[1] = max(newInterval[1], intervals[first_nxt-1][1]);
        if(first_prev + 1 < n) newInterval[0] = min(newInterval[0], intervals[first_prev + 1][0]);
        cout<<"newInterval : "<<newInterval[0]<<", "<<newInterval[1]<<endl;
        
        // create solution
        vvi res;
        for(auto i = 0; i <= first_prev; i++) res.push_back(intervals[i]);
        ll i;
        for(i = first_prev + 1; i < n and intervals[i][0] <= newInterval[1]; i++)
        if(i - 1 >= 0 and intervals[i-1][1] > newInterval[1]) res.push_back({newInterval[1], intervals[i-1][1]});
        res.push_back(newInterval);
        for(; i < n; i++) res.push_back(intervals[i]);
        return res;
        
    }
};