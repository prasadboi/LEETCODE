class Solution {
public:
    
    // DP solution
    int trap_DP(vector<int>& height) 
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
    
    int trap_2pointer(vector<int> &height)
    {
        int n = height.size(), l = 0, r = n-1;
        int l_max = 0, r_max = 0, water = 0;
        while(l < r)
        {
            if(height[r] > height[l]){
                (height[l] > l_max) ? l_max = height[l] : water += l_max - height[l];
                l++;
            }
            else{
                (height[r] > r_max) ? r_max = height[r] : water += r_max - height[r];
                r--;
            }
        }
        return water;
    }
    
    int trap(vector<int>& height) 
    {
        // return trap_DP(height);
        return trap_2pointer(height);
    }
};