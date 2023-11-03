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
    bool check(TreeNode* tmp, long long int l, long long int r) {
       if(!tmp) {
           return true;
       }
       if(tmp->val > l && tmp->val < r) {
          return (check(tmp->left, l, tmp->val) && check(tmp->right, tmp->val, r));
       } return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int l = -2147483650;
        long long int r =  2147483650;
        return check(root, l, r);
    }
};