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
    int ans = 0;
    struct Node {
        bool isBST;
        int sum, mn, mx;
    };
    Node dfs(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.isBST && right.isBST && root->val > left.mx &&
            root->val < right.mn) {
            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            return {true, sum, min(root->val, left.mn),
                    max(root->val, right.mx)};
        }
        return {false, 0, 0, 0};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};