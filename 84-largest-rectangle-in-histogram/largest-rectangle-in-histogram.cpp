class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> numbers, counts;
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int removedCount = 0, h = heights[i];
            while (!numbers.empty() && h < numbers.top()) {
                int oldTopNumber = numbers.top(); numbers.pop();
                int oldTopCount = counts.top(); counts.pop();
                int area = (removedCount + oldTopCount) * oldTopNumber;
                maxArea = max(maxArea, area);
                removedCount += oldTopCount;
            }
            if (numbers.empty() || h > numbers.top()) {
                numbers.push(h);
                counts.push(1 + removedCount);
                continue;
            }
            if (h == numbers.top()) {
                int oldTopCount = counts.top(); counts.pop();
                counts.push(oldTopCount + 1 + removedCount);
            }
        }
        while (numbers.size() > 1) {
            int oldTopNumber = numbers.top(); numbers.pop();
            int oldTopCount = counts.top(); counts.pop();
            int area = oldTopCount * oldTopNumber;
            maxArea = max(maxArea, area);
            int prevTopCount = counts.top(); counts.pop();
            counts.push(prevTopCount + oldTopCount);
        }
        int oldTopNumber = numbers.top();
        int oldTopCount = counts.top();
        return max(maxArea, oldTopCount * oldTopNumber);
    }
};