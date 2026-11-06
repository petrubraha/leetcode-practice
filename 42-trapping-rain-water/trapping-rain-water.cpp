class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int i = 0, j = height.size() - 1;
        int maxI = height[i], maxJ = height[j];
        while (i < j) {
            if (maxI > maxJ) {
                j--;
                total += max(maxJ - height[j], 0);
                maxJ = max(maxJ, height[j]);
            } else {
                i++;
                total += max(maxI - height[i], 0);
                maxI = max(maxI, height[i]);
            }
        }
        return total;
    }
};