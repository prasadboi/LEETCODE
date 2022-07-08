class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n-1;
        for(int i = 0; i < n; i++)
        {   
            i = max(i, l);
            n = min(n, r+1);
            if(nums[i] == 0 and i != l){swap(nums[l], nums[i]); l++; i--;}
            else if(nums[i] == 2 and i != r){swap(nums[i], nums[r]); r--; i--;}
        }
    }
};

// 1 2 0 1