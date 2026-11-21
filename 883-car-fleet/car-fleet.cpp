class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 2 6 10
        // 2 1
        // 2->4->6->8->10
        // 6->7->8->9->10
        // sort positions and speeds
        // the step count c1 <= c2 => same fleet
        // the step count c1 > c2 => fleet count++ update the maxiumum
        // traverse cn-1 cn-2 cn-3
        // for a fleet track the maximum steps
        // 6 8
        // 3 2
        // 10 - 8 / 2
        // 10 - 6 / 3 = 4 / 3
        int n = position.size();
        unordered_map<int, int> posSpd;
        posSpd.reserve(n);
        for (int i = 0; i < n; ++i) {
            posSpd[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());
        double maxSteps = (double)(target - position[n - 1]) / posSpd[position[n - 1]];
        int fleets = 1;
        for (int i = n - 2; i >= 0; --i) {
            double steps = (double)(target - position[i]) / posSpd[position[i]];
            if (steps > maxSteps) {
                maxSteps = steps;
                fleets++;
            }
        }
        return fleets;
    }
};