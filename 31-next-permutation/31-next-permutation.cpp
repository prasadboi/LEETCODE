class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find k such that nums[k] < nums[k+1]
        int k = -1;
        int maxedout = true;
        for(auto i=n-2; i>=0; i--)
            if(nums[i] < nums[i+1]){k = i; maxedout = false; break;}

        if(maxedout){sort(nums.begin(), nums.end()); return;}
        
        int l = -1;
        for(int i = k+1; i < n; i++){
            if(nums[i] > nums[k]) l = i;
        }
        
        swap(nums[l], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
        
    }
};