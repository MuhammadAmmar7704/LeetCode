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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr) {
            TreeNode* tmp = NULL;
            TreeNode* t = NULL;
            bool y = 0;
            if(curr->left) {
                tmp = curr->left;
                while(tmp->right) {
                    tmp = tmp->right;
                }
                y = 1;
            }
            if(y) {
                if(curr->right) {
                    t = curr->right;
                }
                curr->right = curr->left;
                tmp->right = t;
                curr->left = 0;
            }
            curr = curr->right;
        }
    }
};