class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), minimumDistance = n;
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                minimumDistance = min(minimumDistance, abs(startIndex - i));
                minimumDistance = min(minimumDistance, n - startIndex + i);
                minimumDistance = min(minimumDistance, n + startIndex - i);
            }
        }

        if (minimumDistance == n) {
            return -1;
        }
        return minimumDistance;
    }
};