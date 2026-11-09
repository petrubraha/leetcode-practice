class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        int maxLeft = height[l], maxRght = height[r];
        while (l < r) {
            if (maxLeft < maxRght) {
                ++l;
                water += max(maxLeft - height[l], 0);
                maxLeft = max(maxLeft, height[l]);
            } else {
                --r;
                water += max(maxRght - height[r], 0);
                maxRght = max(maxRght, height[r]);
            }
        }
        return water;
    }
};