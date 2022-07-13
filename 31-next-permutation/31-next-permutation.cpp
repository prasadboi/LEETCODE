class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find k such that nums[k] < nums[k+1]
        int k = -1;
        for(auto i=n-2; i>=0; i--)
            if(nums[i] < nums[i+1]){k = i; break;}
        
        // the array is sorted in descending order already
        if(k == -1){reverse(nums.begin(), nums.end()); return;}
        
        // we found a case where nums[k] < nums[k+1]
        if(k >= 0){
            int j = n-1;
            // find the furthest away index to the right that has value larger than nums[k];
            // this must be true other wise we would have had k == -1
            while(nums[j] <= nums[k]) j--;
            // swap the 2 numbers
            swap(nums[j], nums[k]);
            // since everything to the right of j was in descending order the least permutation 
            // greater than nums is the reverse version of that RHS of j (ascending fashion ie)
            //(post swapping)
            reverse(nums.begin() + k + 1, nums.end());
        }
        
    }
};