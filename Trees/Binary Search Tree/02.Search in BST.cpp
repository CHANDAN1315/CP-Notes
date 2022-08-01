// link : https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/
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
    TreeNode* searchBST(TreeNode* root, int v) {
        //dfs
      
        if(root == NULL) return NULL;
        if(root->val == v) return root;
        TreeNode* node;
        
        if(root->val < v){
            node = searchBST(root->right,v);
        }
        else if(root->val > v){
            node = searchBST(root->left,v);
        }
        return node;
        
        // bfs
        while(root!= NULL and root->val != v){
            root = v < root->val ? root->left : root->right;
        }
        return root;
    }
};
