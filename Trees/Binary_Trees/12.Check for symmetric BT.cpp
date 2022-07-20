// Problem link :https://leetcode.com/problems/symmetric-tree/submissions/


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

// TC : O(N)   SC :O(1)+ stack space
class Solution {
public:
    bool isSymmetrichelp(TreeNode* lft, TreeNode* rgt){
        if(lft == NULL || rgt == NULL) return lft == rgt;
        
        if (lft->val != rgt->val) return 0;
        return (isSymmetrichelp(lft->left, rgt->right) && isSymmetrichelp(lft->right,rgt->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetrichelp(root->left, root->right);
    }
};
