class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration)
    {
        if(!slots1.size() or !slots2.size()) return {};
        
        sort(slots1.begin(), slots1.end(), cmp);
        sort(slots2.begin(), slots2.end(), cmp);
        int s1 = 0, s2 = 0;
        for(; s1 < slots1.size() and s2 < slots2.size();)
        {
            if(min(slots1[s1][0], slots2[s2][0]) >= max(slots1[s1][1], slots2[s2][1])){
                // the intervals do NOT overlap
                if(slots1[s1][1] >= slots2[s2][1]) s1++;
                else s2++;
            }
            else
            {
                // there must be some overlap area
                int overlap = min(slots1[s1][1], slots2[s2][1]) - max(slots1[s1][0], slots2[s2][0]);
                if(overlap >= duration)
                    return {max(slots1[s1][0], slots2[s2][0]), max(slots1[s1][0], slots2[s2][0]) + duration};
                else{
                    if(slots1[s1][1] >= slots2[s2][1]) s2++;
                    else s1++;
                }
            }
        }
        return {};
        
    }
};