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
    int count = 0; 

    void countNodes(TreeNode* node, int maxSoFar){
        if(!node) return;
        if(node->val >= maxSoFar) count++;

        maxSoFar = max(maxSoFar,node->val);

        countNodes(node->left,maxSoFar);
        countNodes(node->right,maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        int maxSoFar = root->val;
        countNodes(root,maxSoFar);
        return count;
    }
};
