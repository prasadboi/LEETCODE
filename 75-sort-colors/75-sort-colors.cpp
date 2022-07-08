class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n-1;
        for(int i = 0; i < n; i++)
        {   
            i = max(i, l);
            n = min(n, r+1);
            if(i > -1 and i < n and nums[i] == 0){swap(nums[l], nums[i]); l++; i--;}
            else if(i > -1 and i < n and nums[i] == 2){swap(nums[i], nums[r]); r--; i--;}
        }
    }
};

// 1 2 0 1