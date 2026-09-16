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
    int helper(TreeNode* root, int maxSoFar){
        if(root == NULL)return 0;

        int count = 0;
        if(root->val >= maxSoFar){
            count = 1;
        }

        count += helper(root->left, max(root->val, maxSoFar));
        count += helper(root->right, max(root->val, maxSoFar));

        return count;
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL)return 0;

        return helper(root, root->val);
    }
};
