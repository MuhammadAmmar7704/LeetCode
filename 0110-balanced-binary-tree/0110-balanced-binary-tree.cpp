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
    int balancedfactor(TreeNode*& root) {
        return  ( root? height(root->left) - height(root->right) : -1);
    }
    int height(TreeNode*& root) {
        if(root) {
            int l = height(root->left);
            int r = height(root->right);
            return max(l, r) + 1;
        } return -1;
    }
    int getBalanceFactor(TreeNode* root) {
        if(root) {
            return (height(root->left) - height(root->right));
        } else {
            return -1;
        }
    }
    void check(TreeNode* root, bool& t) {
        if(!root) {
            return;
        }
        check(root->left, t);
        check(root->right, t);
        int y = getBalanceFactor(root);
        if(y != 0 && y != 1 && y != -1) {
            t = false;
        }
    }
    bool isBalanced(TreeNode* root) {
        bool t = true;
        check(root, t);
        return t;
    }
};