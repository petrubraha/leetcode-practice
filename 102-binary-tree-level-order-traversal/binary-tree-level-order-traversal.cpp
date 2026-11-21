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
        // bfs traversal
        // add root to a queue with tag = 0;
        // count = 1
        // result
        // while the queue is not empty
        //    subarray
        //    newLevel count
        //    while count
        //       element  = pop
        //       append to subarray
        //       add children element.tag + 1 and newLevelCount
        //       count--
        //    count = newLevelCount
        //    append subarray to array
        //    tag++
        vector<vector<int>> result;
        deque<TreeNode*> que;
        int count = 0;
        if (root) {
            que.push_back(root);
            count++;
        }
        while (!que.empty()) {
            vector<int> sub;
            int levelCount = 0;
            sub.reserve(2 * count);
            while (count) {
                TreeNode *node = que.front(); que.pop_front();
                sub.push_back(node->val);
                if (node->left) {
                    que.push_back(node->left);
                    levelCount++;
                }
                if (node->right) {
                    que.push_back(node->right);
                    levelCount++;
                }
                count--;
            }
            count = levelCount;
            result.push_back(sub);
        }
        return result;
    }
};