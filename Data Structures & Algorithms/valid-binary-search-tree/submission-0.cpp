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
    bool checkBST(TreeNode* node, long long nodeMax, long long nodeMin){
        if(!node) return true;
        if(node->val >= nodeMax || node->val <= nodeMin) return false;
        
        return checkBST(node->left,node->val,nodeMin) && checkBST(node->right,nodeMax,node->val);
    }

    bool isValidBST(TreeNode* root) {
        long long nodeMin = LLONG_MIN;
        long long nodeMax = LLONG_MAX;
        return checkBST(root,nodeMax,nodeMin);
    }
};
