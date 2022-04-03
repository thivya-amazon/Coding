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
    unordered_map<int, int> iMap;
    TreeNode* treeHelper(vector<int>& P, int startP, int endP, vector<int>& I, int startI, int endI)
    {
        //Base case 1
        if(startP > endP)
            return NULL;
        //Base case 2
        if(startP == endP)
        {
            return new TreeNode(P[startP]);
        }
        //Recursive case
        TreeNode* root = new TreeNode(P[startP]);
        int rootIndex = iMap[P[startP]];
        int numLeft = rootIndex - startI;
        root->left = treeHelper(P, startP+1, startP+numLeft, I, startI, rootIndex-1);
        root->right = treeHelper(P, startP+numLeft+1, endP, I, rootIndex+1, endI);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            iMap[inorder[i]] = i;
        }
        return treeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};