class Solution {
public:
    #define vi vector<int>
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int max_area = 0;
        int l = 0, r = n-1;
        while(l < r)
        {
            max_area = max(min(height[l], height[r])*(r-l), max_area);
            if(height[l] <= height[r]) l++; else r--;
        }
        return max_area;
    }
};