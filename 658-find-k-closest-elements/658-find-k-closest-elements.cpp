class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int,int>,  vector<pair<int, int>>, greater<pair<int,int>>> minheap;
        vector<int> res;
        for(auto i = 0; i < nums.size();i++) minheap.push({abs(nums[i] - x), i});
        for(auto i = 0; i < k and minheap.size(); i++){res.push_back(nums[minheap.top().second]); minheap.pop();}
        sort(res.begin(), res.end());
        return res;
    }
};