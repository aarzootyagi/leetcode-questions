/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);

        while (k--) {
            int sz = q.size();
            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !vis.count(cur->left)) {
                    vis.insert(cur->left);
                    q.push(cur->left);
                }

                if (cur->right && !vis.count(cur->right)) {
                    vis.insert(cur->right);
                    q.push(cur->right);
                }

                if (parent[cur] && !vis.count(parent[cur])) {
                    vis.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
            ans.push_back(q.front()->val), q.pop();
        return ans;
    }
};