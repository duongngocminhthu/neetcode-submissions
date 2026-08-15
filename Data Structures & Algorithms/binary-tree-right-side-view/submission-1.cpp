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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> unvisited;
        vector<int> ans;

        if(root) unvisited.push(root);

        while(!unvisited.empty()){
            int size = unvisited.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = unvisited.front();
                
                if(node){
                    if(node->left) unvisited.push(node->left);
                    if(node->right) unvisited.push(node->right);
                }
                
                if(i == size - 1) ans.push_back(node->val);

                unvisited.pop();
            }
        }

        return ans;
    }
};
