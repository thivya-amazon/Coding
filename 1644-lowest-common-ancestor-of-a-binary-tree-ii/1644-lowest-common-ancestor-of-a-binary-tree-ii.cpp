/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, int> lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return {NULL, 0};
        pair<TreeNode*, int> leftLca = lcaHelper(root->left, p, q);
        pair<TreeNode*, int> rightLca = lcaHelper(root->right, p, q);
        
        //if one of the nodes is root, then we check if the second node is present in any of the subtrees
        if(root == p || root == q)
            return {root, 1+leftLca.second+rightLca.second};
        //if both nodes are present in subtrees
        if(leftLca.first && rightLca.first)
            return{root, 2};
        //if lca is not the root
        return leftLca.first ? leftLca : rightLca;      
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<TreeNode*, int> lca = lcaHelper(root, p, q);
        if(lca.second < 2)
            return NULL;
        return lca.first;
    }
};