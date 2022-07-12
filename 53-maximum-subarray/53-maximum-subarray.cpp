class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -10001, res = -10001;
        if(nums.size() == 0) return 0;
        for(auto i : nums)
        {
            sum = max(sum + i, i);
            res = max(sum, res);
        }
        return res;
    }
};