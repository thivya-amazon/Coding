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
    vector<int> leftBoundary;
    vector<int> leaves;
    vector<int> rightBoundary;
    vector<int> result;
    void getLeftBoundary(TreeNode* node)
    {
        if(!node)
            return;

        leftBoundary.push_back(node->val);
        if(node->left)
            getLeftBoundary(node->left);
        else if(node->right)
            getLeftBoundary(node->right);
    }
    
    void getRightBoundary(TreeNode* node)
    {
        if(!node)
            return;

        rightBoundary.push_back(node->val);
        if(node->right)
            getRightBoundary(node->right);
        else if(node->left)
            getRightBoundary(node->left);

    }
    void getLeaves(TreeNode* node)
    {
        if(!node)
            return;
        if(node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        getLeaves(node->left);
        getLeaves(node->right);
    }
    void getBoundary(TreeNode* root)
    {
        getLeftBoundary(root->left);
        getRightBoundary(root->right);
        getLeaves(root);
        //Remove the boundary leaf since it will be a part of leaves vector
        if(leftBoundary.size())
            leftBoundary.pop_back();
        
        //Remove the boundary leaf since it will be a part of leaves vector and reverse the list to get an anticlockwise list
        if(rightBoundary.size())
        {
            rightBoundary.pop_back();
            reverse(rightBoundary.begin(), rightBoundary.end());
        }
        
        result.push_back(root->val);
        result.insert(result.end(), leftBoundary.begin(), leftBoundary.end());
        result.insert(result.end(), leaves.begin(), leaves.end());
        result.insert(result.end(), rightBoundary.begin(), rightBoundary.end());
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return result;
        if(root->left == NULL && root->right == NULL)
        {
            result.push_back(root->val);
            return result;
        }            
        getBoundary(root);
        return result;
    }
};