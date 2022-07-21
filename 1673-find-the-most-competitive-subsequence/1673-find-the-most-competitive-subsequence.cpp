class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define INF (1e9 + 7)
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // find all subsequences of size k and return the smallest one from them
        stack<int> to_process;
        for(auto i = 0; i < nums.size(); i++)
        {
            while(to_process.size() and to_process.top() > nums[i] and nums.size() + to_process.size() - i > k)
                to_process.pop();
            if(to_process.size() < k) to_process.push(nums[i]);
        }
        vi res;
            while(to_process.size()) {
            res.push_back(to_process.top());
            to_process.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};