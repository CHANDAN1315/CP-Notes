// problem :https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur= cur->right;
            }
            else{
                TreeNode* pre = cur->left;
                while(pre->right and pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = cur; // creating the thread
                    cur = cur->left;
                }
                else{
                    pre->right = NULL; // Removing the thread
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};
