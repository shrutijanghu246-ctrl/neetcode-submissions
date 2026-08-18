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
    vector<int> inorder(TreeNode* root, vector<int>& result){
        if(root == NULL){
            return result;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);

        return result;
    }

    TreeNode* helper(vector<int>& array, int start, int end){
        if (start > end) return nullptr;

        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(array[mid]);

        root->left = helper(array, start, mid - 1);
        root->right = helper(array, mid + 1, end);

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int> result;
        inorder(root, result);

        result.push_back(val);
        sort(result.begin(), result.end());

        return helper(result, 0, result.size() - 1);
    }
};