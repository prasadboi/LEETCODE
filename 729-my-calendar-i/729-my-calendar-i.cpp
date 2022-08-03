class MyCalendar {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    
    map<ll, ll> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(events.size() == 0){events[start] = end-1; return true;}
        auto it = events.lower_bound(start);
        // one interval within the other
        if(it != events.end() and it->first <= start and it->second >= end-1) return false;
        if(it != events.end() and it->first >= start and it->second <= end - 1) return false;
        // partial overlap case:
        // right overlap
        if(it != events.end() and it->first <= end-1) return false;
        //  left overlap
        if(it != events.begin()){
            --it;
            if(it->second >= start) return false;
        }
        events[start] = end - 1;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */