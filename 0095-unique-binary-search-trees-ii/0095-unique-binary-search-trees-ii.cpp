/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        if (start > end)
            return {nullptr};
        vector<TreeNode*> res;

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = build(start, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    res.push_back(node);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) { return build(1, n); }
};