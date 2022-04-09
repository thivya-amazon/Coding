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
    
    bool findPath(TreeNode* root, int value, string& path)
    {
        if(!root)
            return "";
        if(root->val == value)
            return true;
        if(root->left && findPath(root->left, value, path))
            path.push_back('L');
        else if(root->right && findPath(root->right, value, path))
            path.push_back('R');
        if(path.size() == 0)
            return false;
        return true;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string result = "";
        if(root == NULL)
            return "";
        string startNodePath;
        string destNodePath;
        findPath(root, startValue, startNodePath);
        findPath(root, destValue, destNodePath);
        
        while(startNodePath.size() && destNodePath.size() && startNodePath.back() == destNodePath.back())
        {
            startNodePath.pop_back();
            destNodePath.pop_back();
        }
        
        for(int i = 0; i < startNodePath.size(); i++)
        {
            result.push_back('U');
        }
        if(destNodePath.size())
        {
            reverse(destNodePath.begin(), destNodePath.end());
            result += destNodePath;
        }
            
        return result;
    }
};