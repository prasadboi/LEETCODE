class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // k is the first element from the RHS such that nums[k] < nums[k+1]
        int k = -1;
        
        int n = nums.size();
        for(int i = n-2; i>= 0; i--)
            if(nums[i] < nums[i+1]){k = i; break;}
        
        if(k == -1){ 
            // the array is in descending order so there exists no larger permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // otherwise
        // 1. find the element furthest away from idx k which is larger than nums[k]
        // there must be such an element other wise k == -1 (already handled)
        int rtmost_greater = n-1;
        while(nums[k] >= nums[rtmost_greater]) rtmost_greater--;
        // 2. swap rtmost_greater and k positions
        swap(nums[k], nums[rtmost_greater]);
        // 3. reverse the subarray nums[k+1 : ]
        reverse(nums.begin() + k + 1, nums.end());
    }
};