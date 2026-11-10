class Solution {
    void updateCount(stack<int>& counts, int count) {
        if (counts.empty()) {
            return;
        }
        int oldTop = counts.top(); counts.pop();
        counts.push(oldTop + count);
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> values, counts;
        for (int i = 0; i < n; ++i) {
            int biggerCount = 0;
            while (!values.empty() && heights[i] < values.top()) {
                int oldTopValue = values.top(); values.pop();
                int oldTopCount = counts.top(); counts.pop();
                int area = oldTopValue * (oldTopCount + biggerCount);
                maxArea = max(maxArea, area);
                biggerCount += oldTopCount;
            }
            if (values.empty() || heights[i] > values.top()) {
                values.push(heights[i]);
                counts.push(1 + biggerCount);
            } else if (!values.empty() && heights[i] == values.top()) {
                updateCount(counts, 1 + biggerCount);
            }
        }
        while (!values.empty()) {
            int oldTopValue = values.top(); values.pop();
            int oldTopCount = counts.top(); counts.pop();
            int area = oldTopValue * oldTopCount;
            maxArea = max(maxArea, area);
            updateCount(counts, oldTopCount);
        }
        return maxArea;
    }
};
