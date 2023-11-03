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
    int go(TreeNode* tmp, int& m_max) {
        if(!tmp) {
            return 0;
        }
        int l = go(tmp->left, m_max);
        int r = go(tmp->right, m_max);
        if(l < 0) {
            l = 0;
        }
        if(r < 0) {
            r = 0;
        }
        m_max = max(m_max, l + r + tmp->val);
        
        return tmp->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int m_max = root->val;
        int y = go(root, m_max);
        return m_max;
    }
};