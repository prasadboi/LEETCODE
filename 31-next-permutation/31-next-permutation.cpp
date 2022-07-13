class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find k such that nums[k] < nums[k+1]
        int k = -1;
        for(auto i=n-2; i>=0; i--)
            if(nums[i] < nums[i+1]){k = i; break;}
        
        if(k == -1){reverse(nums.begin(), nums.end()); return;}
        
        if(k >= 0){
            int j = n-1;
            while(nums[j] <= nums[k]) j--;
            swap(nums[j], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
        
    }
};