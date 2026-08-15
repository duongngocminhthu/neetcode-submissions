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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> unvisited;
        vector<vector<int>> ans;

        unvisited.push(root);

        while(!unvisited.empty()){
            int size = unvisited.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode* node = unvisited.front();
                
                if(node){
                    level.push_back(node->val);
                    unvisited.push(node->left);
                    unvisited.push(node->right);
                }
                
                unvisited.pop();
            }

            if(!level.empty()) ans.push_back(level);
        }

        return ans;
    }
};
