/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serial;
    void preorderHelper(TreeNode* root)
    {
        if(root == NULL)
            return;
        serial.append(to_string(root->val));
        serial.push_back(' ');
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        preorderHelper(root);
        cout << serial;
        return serial;
    }
    // Decodes your encoded data to tree.
    
    int binarySearch(vector<int>& arr, int start, int end, int target)
    {
        if(start > end)
            return -1;
        int mid = start + (end - start)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            return binarySearch(arr, start, mid-1, target);
        else
            return binarySearch(arr, mid+1, end, target);
    }
    TreeNode* bstHelper(vector<int>& preorder, vector<int>& inorder, int startP, int endP, int startI, int endI)
    {
        if(startI > endI)
            return NULL;
        TreeNode* root = new TreeNode(preorder[startP]);
        vector<int> :: iterator it = find(inorder.begin(), inorder.end(), root->val);
        int Ri = it - inorder.begin(); //binarySearch(inorder, startI, endI, root->val);
        int numLeft = Ri-startI;
        root->left = bstHelper(preorder, inorder, startP+1, startP+numLeft, startI, Ri-1);
        root->right = bstHelper(preorder, inorder, startP+numLeft+1, endP, Ri+1, endI);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return bstHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
   }
    TreeNode* deserialize(string data) {
        vector<int> array;
        stringstream ss(data);
        string elem;
        while(ss >> elem)
        {
            array.push_back(stoi(elem));
        }
        return bstFromPreorder(array);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;