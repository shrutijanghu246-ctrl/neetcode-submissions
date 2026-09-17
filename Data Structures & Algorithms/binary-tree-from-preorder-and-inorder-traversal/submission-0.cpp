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
    int preIndex = 0;
    unordered_map<int, int> inorderMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preOrder, int inStart, int inEnd){
        if(inStart > inEnd)return nullptr;

        int rootVal = preOrder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->left = build(preOrder, inStart, mid - 1);
        root->right = build(preOrder, mid + 1, inEnd);

        return root;
    }
};
