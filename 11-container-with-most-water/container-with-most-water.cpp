class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), area = 0;
        for (int i = 0, j = n - 1; i < j; ) {
            int size = (j - i) * min(heights[j], heights[i]);
            area = max(area, size);
            heights[i] < heights[j] ? i++ : j--;
        }
        return area;
    }
};
