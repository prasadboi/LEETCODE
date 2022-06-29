class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;    // ans
        deque<int> window; // keeps indices of all elements in the window
        int n = nums.size();
        
        for(int i = 0; i < k and i < n; i++){
            while(window.size() and nums[i] >= nums[window.front()]) window.pop_front();
            while(window.size() and nums[i] >= nums[window.back()]) window.pop_back();
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);
        
        for(int i = k; i < n; i++)
        {
            if(window.size() and window.front() == (i-k)) window.pop_front();
            while(window.size() and nums[i] >= nums[window.front()]) window.pop_front();
            while(window.size() and nums[i] >= nums[window.back()]) window.pop_back();
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};