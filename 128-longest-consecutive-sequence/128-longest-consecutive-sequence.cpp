class Solution {
public:
    #define uset unordered_set
    
    int longestConsecutive(vector<int>& nums) {
        uset<int> s(nums.begin(), nums.end());
        if(s.size() <= 0) return 0;
        int res = 1;
        for(auto& i : s)
        {
            int curr_len = 1;
            for(int j = i; s.count(j-1); j--) {s.erase(j-1); curr_len++;}
            for(int j = i; s.count(j+1); j++) {s.erase(j+1); curr_len++;}
            res = max(res, curr_len);
        }
        return res;
    }
};