class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeftHeights(n, 0), maxRghtHeights(n, 0);
        for (int i = 1; i < n; ++i) {
            maxLeftHeights[i] = max(maxLeftHeights[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            maxRghtHeights[i] = max(maxRghtHeights[i + 1], height[i + 1]);
        }
        int water = 0;
        for (int i = 1; i < n; ++i) {
            water += max(min(maxLeftHeights[i], maxRghtHeights[i]) - height[i], 0);
        }
        return water;
    }
};
