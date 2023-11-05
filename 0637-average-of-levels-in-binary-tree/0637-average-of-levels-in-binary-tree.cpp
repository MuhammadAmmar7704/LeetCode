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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) {
            // return ans;
            return ans;
        }
        TreeNode* tt = 0;
        queue<TreeNode*> t;
        t.push(root);
        while(!t.empty()) {
            int s = t.size();
            double ttt = 0;
            for(int i = 0; i < s && !t.empty(); ++i) {
                tt = t.front();
                t.pop();
                ttt += (double)tt->val;
                if(tt->left) {
                    t.push(tt->left);
                }
                if(tt->right) {
                    t.push(tt->right);
                }
            }
            ans.push_back(ttt / s);
        }
        return ans;
    }
};