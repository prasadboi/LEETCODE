class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        for(auto i : nums) freq[i]++;
        
        auto cmp = [](pair<int, int> &a, pair<int, int> &b){return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minheap(cmp);
        for(auto i : freq){
            minheap.push({i.first, i.second});
            if(minheap.size() > k) minheap.pop();
        }
        vector<int> res;
        while(minheap.size())
        {
            res.push_back(minheap.top().first); 
            minheap.pop();
        }
        return res;
    }
};