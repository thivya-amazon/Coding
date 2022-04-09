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
    vector<TreeNode*> result;
    unordered_map<string, int> umap;
    string dfs(TreeNode* node)
    {
        if(!node)
            return "";
        string left = dfs(node->left);
        string right = dfs(node->right);
        
        string mySubTree = "(" + left + to_string(node->val) + right + ")";
        if(umap[mySubTree] == 1)
            result.push_back(node);
        umap[mySubTree]++;
        
        return mySubTree;
    }
        
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL)
            return result;
      dfs(root);
        return result;
    }
};