class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root , LONG_MIN , LONG_MAX);
    }
    bool valid(TreeNode* node , long mini, long maxi){
        if(node==nullptr) return true;
        if(!(node->val > mini && node->val < maxi)) return false;
        return valid(node->left , mini , node->val) && valid(node->right , node->val , maxi);
    }
};