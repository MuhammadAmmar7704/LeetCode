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
    TreeNode* get(TreeNode* root, int x) {
        if(!root) {
            return NULL;
        }
        if(root->val == x) {
            return root;
        }
        TreeNode* t = get(root->left, x);
        if(t) {
            return t;
        }
        return get(root->right, x);
    }
    
    bool check(TreeNode* root, TreeNode* x, TreeNode* y) {
        if(!root) {
            return false;
        }
        int tt = 0;
        return ((root->left == x && root->right == y) || (root->left == y && root->right == x)) || check(root->left, x, y) || check(root->right, x, y); 
    }
    int getlevel(TreeNode* root, TreeNode* x, int ans) {
        if(!root) {
            return 0;
        }
        if(root == x) {
            return ans;
        }
        int l = getlevel(root->left, x, ans + 1);
        if(l != 0) {
            return l;
        }
        return getlevel(root->right, x, ans + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xNode = get(root, x);
        TreeNode* yNode = get(root, y);
        return (getlevel(root, xNode, 0) == getlevel(root, yNode, 0) && !check(root, xNode, yNode));
    }
};