class KthLargest {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k;
    KthLargest(int x, vector<int>& nums) {
        k = x;
        for(auto i : nums) maxheap.push(i);
        int ctr = 0;
        while(maxheap.size() and ctr < k-1){minheap.push(maxheap.top()); maxheap.pop(); ctr++;}
    }
    
    int add(int val) {
        if(minheap.size() and val > minheap.top()){
            minheap.push(val);
            while(minheap.size() > k-1){maxheap.push(minheap.top()); minheap.pop();}
        }
        else maxheap.push(val);
        return (maxheap.size()) ? maxheap.top() : INT_MIN;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */