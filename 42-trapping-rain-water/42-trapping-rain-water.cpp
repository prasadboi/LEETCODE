class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i-1], height[i-1]);
        for(int i = n-2; i >= 0; i--) suffix[i] = max(height[i+1], suffix[i+1]); 
        
        int water = 0;
        for(int i = 0; i < n; i++)
        {
            // cout<<"water added = "<<max(0, min(suffix[i], prefix[i]) - height[i])<<endl;
            water += max(0, min(suffix[i], prefix[i]) - height[i]);
        }
        return water;
    }
};