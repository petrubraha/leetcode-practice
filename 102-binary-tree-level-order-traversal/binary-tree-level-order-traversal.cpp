/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        deque<TreeNode*> que;
        que.push_back(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> sub;
            sub.reserve(2 * size);
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front(); que.pop_front();
                sub.push_back(node->val);
                if (node->left) {
                    que.push_back(node->left);
                }
                if (node->right) {
                    que.push_back(node->right);
                }
            }
            result.push_back(sub);
        }
        return result;
    }
};