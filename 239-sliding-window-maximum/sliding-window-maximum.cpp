class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        deque<int> q;
        vector<int> result;
        result.reserve(n);
        while (r < n) {
            while (!q.empty() && nums[r] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(r);
            if (l > q.front()) {
                q.pop_front();
            }
            if (r >= k - 1) {
                result.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return result;
    }
};