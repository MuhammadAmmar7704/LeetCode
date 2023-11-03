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
    int ans = 0;
    int count = 0;
    void check(TreeNode* root, int k) {
        if(!root) {
            return;
        }
        check(root->left, k);
        count++;
        if(count == k)
            ans = root->val;
        check(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        check(root, k);
        return ans;
    }
};