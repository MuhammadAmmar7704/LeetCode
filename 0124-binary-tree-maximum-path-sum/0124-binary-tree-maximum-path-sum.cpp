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
    int maxpath;
    int go(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int l = go(root->left);
        int r = go(root->right);
        l = max(l, 0);
        r = max(r, 0);
        maxpath = max(l + r + root->val, maxpath);
        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxpath = root->val;
        go(root);
        return maxpath;
    }
};