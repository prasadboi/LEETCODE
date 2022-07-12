class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap(nums.begin(), nums.end());
        if(k > maxheap.size()) return -1;
        int ctr = 0;
        while(maxheap.size() and ctr < k-1)ctr++, maxheap.pop();
        return maxheap.top();
    }
};