class Solution {
    bool checksAndAdds(unordered_set<char>& nums, char chr) {
        if (chr == '.') {
            return false;
        }
        if (nums.find(chr) != nums.end()) {
            return true;
        }
        nums.insert(chr);
        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<char>, 9> columnSets, squareSets;
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; ++j) {
                if (checksAndAdds(rowSet, board[i][j]) ||
                    checksAndAdds(columnSets[j], board[i][j]) ||
                    checksAndAdds(squareSets[(i / 3) * 3 + j / 3], board[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
};