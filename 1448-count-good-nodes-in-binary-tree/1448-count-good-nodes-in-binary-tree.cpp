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
    void check(TreeNode* root, int& ans, int maxi, int tt) {
        if(!root) {
            return;
        }
        bool y = 0;
        if(root->val >= maxi && root->val >= tt) {
            ++ans;
            y = 1;
        }
        if(root->left)
            if(y)
                check(root->left, ans, root->val, root->val);
            else check(root->left, ans, maxi, root->val);
        if(root->right)
            if(y)
                check(root->right, ans, root->val, root->val);
            else check(root->right, ans, maxi, root->val);
       
    }
    int goodNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans = 0;
        
        check(root, ans, root->val, root->val);
        return ans;
    }
};