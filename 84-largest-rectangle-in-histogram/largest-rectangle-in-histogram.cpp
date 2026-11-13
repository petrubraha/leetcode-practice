class Solution {
    void updateTop(stack<int>& stk, int newTop) {
        stk.pop();
        stk.push(newTop);
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> values, counts;
        int n = heights.size(), maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int h = heights[i], eliminatedCounts = 0;
            while (!values.empty() && h < values.top()) {
                int oldValue = values.top(); values.pop();
                int oldCount = counts.top(); counts.pop();
                int area = oldValue * (oldCount + eliminatedCounts);
                maxArea = max(maxArea, area);
                eliminatedCounts += oldCount;
            }
            if (values.empty() || h > values.top()) {
                values.push(h);
                counts.push(1 + eliminatedCounts);
                continue;
            }
            if (h == values.top()) {
                updateTop(counts, counts.top() + 1 + eliminatedCounts);
            }
        }
        while (!values.empty()) {
            int oldValue = values.top(); values.pop();
            int oldCount = counts.top(); counts.pop();
            int area = oldValue * oldCount;
            maxArea = max(maxArea, area);
            if (!counts.empty()) {
                updateTop(counts, counts.top() + oldCount);
            }
        }
        return maxArea;
    }
};