class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maximum = 0;
        for (int i = 0, j = heights.size() - 1; i < j; ) {
            maximum = max(maximum, (j - i) * min(heights[i], heights[j]));
            if (heights[i] > heights[j]) {
                j--;
            } else {
                i++;
            }
        }
        return maximum;
    }
};