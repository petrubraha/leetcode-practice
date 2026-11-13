class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int, int> spd;
        spd.reserve(n);
        for (int i = 0; i < n; ++i) {
            spd[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());
        int fleetCount = 1;
        double maximumTime = (double)(target - position[n - 1]) / spd[position[n - 1]];
        for (int i = n - 2; i >= 0; --i) {
            double time = (double)(target - position[i]) / spd[position[i]];
            if (time > maximumTime) {
                fleetCount++;
                maximumTime = time;
            }
        }
        return fleetCount;
    }
};