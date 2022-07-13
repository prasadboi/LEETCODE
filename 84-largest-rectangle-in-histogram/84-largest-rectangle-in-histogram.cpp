class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        s.push(-1);
        int max_area = 0;
        for(int i = 0; i < n; i++)
        {
            while(s.top() != -1 and heights[s.top()] >= heights[i]){
                int h = heights[s.top()];
                s.pop();
                int w = i - s.top() - 1;
                max_area = max(max_area, h*w);
            }
            s.push(i);
        }
        while(s.top() != -1)
        {
            int h = heights[s.top()];
            s.pop();
            int w = n - s.top() - 1;
            max_area = max(max_area, h*w);
        }
        return max_area;
    }
};