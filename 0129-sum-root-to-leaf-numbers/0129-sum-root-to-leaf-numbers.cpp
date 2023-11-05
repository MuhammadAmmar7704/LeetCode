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
    void find(TreeNode* root, vector<int>& ans, int sum) {
        if(!root) {
            return;
        }
        if(root->left == 0 && root->right == 0) {
            ans.push_back(sum);
        }
        if(root->left) 
            find(root->left, ans, sum*10 + root->left->val);
        if(root->right)
            find(root->right, ans, sum*10 + root->right->val);
        
    }
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        find(root, ans, root->val);
        for(int i = 1; i < ans.size(); ++i) 
            ans[0] += ans[i];
        return ans[0];
    }
};