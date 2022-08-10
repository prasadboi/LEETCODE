class Solution {
public:
    #define pq priority_queue
    #define umap unordered_map
    #define vi vector<int>
    #define vpii vector<pair<int, int>>
    #define pii pair<int, int>
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int rooms = 0;
        auto cmp = [](vi &a, vi &b){return a[1] > b[1];};
        pq<vi, vector<vi>, decltype(cmp)> minheap(cmp);
        sort(intervals.begin(), intervals.end());        
        
        if(intervals.size() == 0) return 0;
        int end;
        minheap.push({INT_MAX, INT_MAX});
        for(auto i : intervals)
        {
            end = minheap.top()[1];
            // cout<<"end = "<<end<<", i[0] = "<<i[0]<<", i[1] = "<<i[1]<<endl;
            if(end > i[0]) rooms++; // no free rooms from earlier available
            else minheap.pop(); // a room has freed up and we can use that
            minheap.push(i); // inserting the new end time till which this room will be occupied
        }
        return rooms;
    }
};