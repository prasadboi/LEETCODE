/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};


class Solution {
public:
    #define ll long long int
    #define vintv vector<Interval>
    #define vvintv vector<vintv>
    #define vi vector<int>
    #define umap unordered_map
    #define uset unordered_set
    #define vll vector<ll>
    #define vvll vector<vll>
    #define pq priority_queue
    #define pii pair<int, int>
    #define vpii vector<pii>
    #define vvpii vector<vpii>
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) 
    {
        vintv res;
        int minstart = INT_MAX, maxend = INT_MIN;
        for(auto i : schedule){
            minstart = min(minstart, i[0].start), maxend = max(maxend, i[i.size()-1].end);
            heap.push(i[0]);
        }
        int start = minstart, end = minstart;
        for(auto ctr = minstart; ctr <= maxend and heap.size();)
        {
            bool free = true;
            // cout<<"ctr = "<<ctr<<endl;
            for(auto i = schedule.begin(); i != schedule.end(); i++)
            {
                vintv v((*i).begin(), (*i).end());
                while(v.size() and ctr > v[0].end) v.erase(v.begin());
                if(v.size() and ctr > v[0].start)
                {
                    // cout<<"start : "<<start<<", end = "<<end<<endl;
                    if(start != end) res.push_back(Interval(start, end));
                    free = false;
                    ctr = v[0].end; start = ctr; end = ctr;
                    v.erase(v.begin()); (*i) = v;
                    // cout<<"collision : new ctr = "<<ctr<<endl;
                    break;
                }
            }
            if(free) end = ctr++;
        }
        return res;
    }
};



*/

class Solution {
public:
    #define ll long long int
    #define vintv vector<Interval>
    #define vvintv vector<vintv>
    #define vi vector<int>
    #define umap unordered_map
    #define uset unordered_set
    #define vll vector<ll>
    #define vvll vector<vll>
    #define pq priority_queue
    #define pii pair<int, int>
    #define vpii vector<pii>
    #define vvpii vector<vpii>
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) 
    {
        auto cmp = [](pair<int, Interval> &a, pair<int, Interval> &b){
            return a.second.start > b.second.start;
        };
        vintv res;
        pq<pair<int, Interval>, vector<pair<int, Interval>>, decltype(cmp)> heap(cmp);
        
        for(auto i = 0; i < schedule.size(); i++) heap.push({i, schedule[i][0]});
        
        int end = heap.top().second.start;
        while(heap.size())
        {
            int empidx = heap.top().first;
            Interval work = heap.top().second;
            heap.pop();
            if(end < work.start){
                res.push_back(Interval(end, work.start));
                end = work.end;
            }
            else
                end = max(end, work.end);
            
            if(schedule[empidx].size())
            {
                heap.push({empidx, schedule[empidx][0]});
                schedule[empidx].erase(schedule[empidx].begin());
            }
        }
        return res;
    }
};