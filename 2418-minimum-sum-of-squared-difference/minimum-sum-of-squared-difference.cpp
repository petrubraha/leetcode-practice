class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        map<int, int> diffToIdxMap;

        // sorted differences
        const int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            diffToIdxMap[diff]++;
        }

        int changesAvailable = k1 + k2;
        while (changesAvailable > 0) {
            // take the maximum diff.
            auto it = diffToIdxMap.rbegin();
            int oldDiff = it->first;
            if (oldDiff == 0) {
                break;
            }

            int oldCount = it->second;
            if (oldCount > changesAvailable) {
                it->second = oldCount - changesAvailable;
                diffToIdxMap[--oldDiff] += changesAvailable;
                break;
            }

            changesAvailable -= oldCount;
            diffToIdxMap.erase(oldDiff);
            diffToIdxMap[--oldDiff] += oldCount;
        }

        for (auto it = diffToIdxMap.crbegin(); it != diffToIdxMap.crend(); ++it) {
            long long multiplier = it->second;
            ans += multiplier * it->first * it->first;
        }
        return ans;
    }
};