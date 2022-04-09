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
    vector<pair<TreeNode*, TreeNode*>> comp;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(prev != NULL && prev->val > root->val)
            comp.push_back({prev, root});
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        inorder(root);
        //adjacent nodes are swapped
        if(comp.size() == 1)
            swap(comp[0].first->val, comp[0].second->val);
        else if(comp.size() > 1)
            swap(comp[0].first->val, comp[1].second->val);
    }
};