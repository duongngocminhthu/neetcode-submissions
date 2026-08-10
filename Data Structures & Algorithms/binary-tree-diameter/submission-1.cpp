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
    int diameter = 0;

    int findDiameter(TreeNode* root){
        if(!root) return 0;

        int maxLeft = findDiameter(root->left);
        int maxRight = findDiameter(root->right);

        int maxLen = maxLeft + maxRight;
        diameter = max(diameter,maxLen);

        return 1 + max(maxLeft,maxRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        findDiameter(root);
        return diameter;
    }
};
