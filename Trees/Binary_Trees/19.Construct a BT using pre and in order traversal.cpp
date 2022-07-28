//Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// note : always try to pass data stracture like vector and map by reference as by value create copy which lead to TLE and MLE
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for(int i =0; i<n; i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildNew(preorder, 0, preorder.size()-1,
                                  inorder, 0, inorder.size()-1, mpp);
            
        return root;
    }
    TreeNode* buildNew(vector<int>& pre, int preStart, int preEnd, vector<int>& in,
                       int inStart, int inEnd, unordered_map<int, int>& mpp)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(pre[preStart]);
        int inroot = mpp[node->val];
        int numleft = inroot - inStart;
        
        node->left = buildNew(pre, preStart+1, preStart+numleft, in , 
                              inStart, inroot-1,mpp);
        
        node->right = buildNew(pre,preStart+numleft+1, preEnd, in, 
                               inroot+1, inEnd, mpp);
        
        return node;
    }
    
};
