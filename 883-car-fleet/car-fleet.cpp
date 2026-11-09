class Solution {
    double getTime(int target, int pos, int spd) {
        return (double)(target - pos) / spd;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int, int> spd;
        for (int i = 0; i < n; ++i) {
            spd[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());
        stack<double> time;
        time.push(getTime(target, position[n - 1], spd[position[n - 1]]));
        for (int i = n - 2; i >= 0; --i) {
            double tme = getTime(target, position[i], spd[position[i]]);
            if (tme > time.top()) {
                time.push(tme);
            }
        }
        return time.size();
    }
};
