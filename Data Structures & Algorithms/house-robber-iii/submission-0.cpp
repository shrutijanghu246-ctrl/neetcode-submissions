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
    pair<int, int> dfs(TreeNode* node){
        if(!node) return {0, 0};

        auto [leftRob, leftNotRob] = dfs(node->left);
        auto [rightRob, rightNotRob] = dfs(node->right);

        int rob = node->val + leftNotRob + rightNotRob;
        int notRob = max(leftNotRob, leftRob) + max(rightNotRob, rightRob);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        auto[robRoot, notRobRoot] = dfs(root);

        return max(robRoot, notRobRoot);
    }
};