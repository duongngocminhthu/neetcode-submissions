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
    unordered_map<int,int> inorderMap;

    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int inLeft, int inRight){
        if(inLeft > inRight) return nullptr;

        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        root->left = build(preorder,inLeft,inorderMap[rootValue] - 1);
        root->right = build(preorder,inorderMap[rootValue] + 1,inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return build(preorder,0,inorder.size()-1);
    }
};
