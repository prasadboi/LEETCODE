class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        s.push(-1); // marks the end of the stack
        int max_area = 0;
        for(int i = 0; i < n; i++)
        {
            while(s.top() != -1 and heights[s.top()] >= heights[i]){
                int h = heights[s.top()]; // largest element encountered = H
                                          // = height[i - 1]
                s.pop();
                int w = i - s.top() - 1; // index of largest element left of H = L
                                         // w = (i-1) - L
                max_area = max(max_area, h*w);
            }
            s.push(i);
        }
        // (H[s.top()] = max, H[s.bottom()] = min)
        // all the elements to right of s.top and all the elements between s.top() and s.2ndtop()
        // would be greater than H[s.top()]
        // hence height = H[s.top()], and width  = n - s.2ndtop() - 1;
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