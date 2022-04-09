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
    unordered_map<long, int> umap;
    int count = 0;
    void dfs(TreeNode* node, long targetSum, long prefixSum)
    {
        if(node == NULL)
            return;
        prefixSum += node->val;
        
        if(umap.find(prefixSum - targetSum) != umap.end())
            count += umap[prefixSum - targetSum];
        
        //update prefixSum in the hashmap
        if(umap.count(prefixSum))
            umap[prefixSum]++;
        else
            umap[prefixSum] = 1;
        
        dfs(node->left, targetSum, prefixSum);
        dfs(node->right, targetSum, prefixSum);
        
        umap[prefixSum]--;
        if(umap[prefixSum] == 0)
            umap.erase(prefixSum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        //prefix sum of 0 exists once - empty tree case
        umap[0] = 1;
        dfs(root, targetSum, 0);
        return count;
    }
};