#define ll long long int
#define pq priority_queue
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vb vector<bool>
#define INF (1e9 + 7)

class MedianFinder {
public:
    pq<ll, vll, greater<ll>> min_heap;
    pq<ll> max_heap;
    MedianFinder() {}
    
    void addNum(int num) {
        // cout<<"called add num for : "<<num<<endl;
        if(max_heap.size() == 0 or max_heap.top() >= (ll) num)
        {
            max_heap.push((ll)num);
            while(max_heap.size() and max_heap.size() > min_heap.size() + 1){
                min_heap.push(max_heap.top()); max_heap.pop();
            }
        }
        else
        {
            min_heap.push((ll) num);
            while(min_heap.size() and min_heap.size() > max_heap.size()){
                max_heap.push(min_heap.top()); min_heap.pop();
            }
        }
        // cout<<"pushed num : "<<num<<endl;
    }
    
    double findMedian() {
        if(max_heap.size() > min_heap.size()) return (double)max_heap.top();
        else return (double)(max_heap.top() + min_heap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */