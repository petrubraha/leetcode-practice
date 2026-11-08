// 11:46
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(), maxFreq = -1;
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (auto num : nums) {
            maxFreq = max(maxFreq, ++freq[num]);
        }
        vector<int> cnt(maxFreq + 1, 0);
        for (const auto& [num, f] : freq) {
            cnt[f]++;
        }
        int t = maxFreq, below = 0;
        while (below + cnt[t] < k) {
            below += cnt[t--];
        }
        int tieSlots = k - below;        
        vector<int> result;
        result.reserve(k);
        for (const auto& [num, f] : freq) {
            if (f > t) {
                result.emplace_back(num);
            } else if (f == t && tieSlots > 0) {
                result.emplace_back(num);
                tieSlots--;
            }
        }
        return result;
    }
};
