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
        // once you have done this much now you only have all the in the stack in 
        // sorted order such that each element in stack is smaller than all the 
        // elements on its left 
        // (H[s.top()] = max, H[s.bottom()] = min)
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