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
    bool check(TreeNode* l, TreeNode* r) {
        if(!l && !r) {
            return true;
        }
        if((!l && r) || (l && !r)) {
            return false;
        }
        bool a = 0, b = 0;
        if(l->left && r->right) {
            if(l->left->val == r->right->val) 
                a = 1;
        } else if(!l->left && !r->right) {
            a = 1;
        }
        if(l->right && r->left) {
           if(l->right->val == r->left->val)
               b = 1;
        } else if(!l->right && !r->left) {
            b = 1;
        }
        if(a && b)
            return (check(l->left, r->right) && (check(l->right, r->left)));
        else 
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        if(root->left && root->right) {
            if(root->left->val == root->right->val)
                return check(root->left, root->right);
        } else if((!root->left && root->right) || (root->left && !root->right)) {
            return false;
        } else {
            return true;
        }
            
        return false;
    }
};