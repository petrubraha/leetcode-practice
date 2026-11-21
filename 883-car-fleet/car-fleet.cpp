class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        int fleets = 0;
        double maxTime = 0;
        for (int i = 0; i < n; ++i) {
            if (cars[i].second > maxTime) {
                fleets++;
                maxTime = cars[i].second;
            }
        }
        return fleets;
    }
};