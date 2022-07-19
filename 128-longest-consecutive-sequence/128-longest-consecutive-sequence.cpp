class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for(auto i : nums) cout<<i<<" "; cout<<endl;
        int ctr = 1, res = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) continue;
            else if(nums[i] > nums[i-1] + 1) ctr = 1;
            else ctr++;
            // cout<<"ctr : "<<ctr<<endl;
            res = max(res, ctr);
        }
        return res;
    }
};