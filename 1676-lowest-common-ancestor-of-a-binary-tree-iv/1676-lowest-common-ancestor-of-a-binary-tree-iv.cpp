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
    TreeNode* lcaHelper(TreeNode* root, vector<TreeNode*> &nodes)
    {
        if(root == NULL)
            return NULL;
        set<TreeNode*> nodeSet(nodes.begin(), nodes.end());
                
        if(nodeSet.count(root))
        {
            return root;
        }
        TreeNode* left_lca = lcaHelper(root->left, nodes);
        TreeNode* right_lca = lcaHelper(root->right, nodes);

        if(left_lca && right_lca)
            return root;
        return left_lca ? left_lca : right_lca;      
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        int count = 0;
        TreeNode* result = lcaHelper(root, nodes);
      
        return result;
        return NULL;
    }
};