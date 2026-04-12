class Solution {
    static constexpr int LETTER_COUNT = 26;
public:
    int getDistance(int character0, int character1) {
        return abs(character0 / 6 - character1 / 6) +
            abs(character0 % 6 - character1 % 6);
    }

    int minimumDistance(string word) {
        int n = word.size(), dp[300][LETTER_COUNT][LETTER_COUNT];
        memset(dp + 1, 1e6, 299 * LETTER_COUNT * LETTER_COUNT * sizeof(int));

        for (int i = 0; i < n; ++i) {
            int character = word[i] - 'A';
            for (int j = 0; j < LETTER_COUNT; ++j) {
                for (int k = 0; k < LETTER_COUNT; ++k) {
                    dp[i + 1][j][character] = min(dp[i + 1][j][character], dp[i][j][k] + getDistance(k, character));
                    dp[i + 1][character][k] = min(dp[i + 1][character][k], dp[i][j][k] + getDistance(j, character));
                }
            }
        }

        int distance = 1e6;
        for (int j = 0; j < LETTER_COUNT; ++j) {
            for (int k = 0; k < LETTER_COUNT; ++k) {
                distance = min(distance, dp[n][j][k]);
            }
        }
        
        return distance;
    }
};