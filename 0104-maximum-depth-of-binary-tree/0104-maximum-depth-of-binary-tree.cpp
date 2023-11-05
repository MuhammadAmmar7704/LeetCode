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
    int run(TreeNode* root) {
        if(root) {
            int l = run(root->left);
            int r = run(root->right);
            return max(l, r) + 1;
        } return 0;
    }
    int maxDepth(TreeNode* root) {
        return run(root);
    }
};