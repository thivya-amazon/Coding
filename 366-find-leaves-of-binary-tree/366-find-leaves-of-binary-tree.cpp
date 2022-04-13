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
    unordered_map<int, vector<int>> umap;
    int getHeight(TreeNode* node)
    {
        if(!node)
            return -1;
        int lh = getHeight(node->left) + 1;
        int rh = getHeight(node->right) + 1;
        
        int height = max(lh,rh);
        umap[height].push_back(node->val);
        
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        int maxHeight = getHeight(root);
        for(int i = 0; i <= maxHeight; i++)
        {
            result.push_back(umap[i]);
        }
       return result; 
    }
};