class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (((n + m) % 2 != 1) || grid[0][0] == ')' || grid[n - 1][m - 1] == '(') {
            return false;
        }

        vector<unordered_set<int>> possibleBalances(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int balance = grid[i][j] == '(' ? 1 : -1;
                if (i == 0 && j == 0) {
                    possibleBalances[0].insert(balance);
                    continue;
                }

                unordered_set<int> newSet{};

                // Above case.
                for (int possibleBalance : possibleBalances[j]) {
                    int newBalance = possibleBalance + balance;
                    if (newBalance > -1) {
                        newSet.insert(newBalance);
                    }
                }

                // Left case.
                if (j > 0) {
                    for (int possibleBalance : possibleBalances[j - 1]) {
                        int newBalance = possibleBalance + balance;
                        if (newBalance > -1) {
                            newSet.insert(newBalance);
                        }                    
                    }
                }

                possibleBalances[j] = newSet;
            }
        }

        return possibleBalances[m - 1].contains(0);
    }
};