class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        if(l == nums.end() or *l != target) return {-1, -1};
        auto u = upper_bound(nums.begin(), nums.end(), target);
        int lidx = l - nums.begin();
        if(u != nums.begin()){
            --u; 
            int ridx = u - nums.begin();
            if(*u != target) 
                return {-1, -1}; 
            else 
                return {lidx, ridx};
        }
        return {-1, -1};
    }
};