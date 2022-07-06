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
    // The code that i worte do not cover the edge case of -ve and 0 value combination but this code does
    //TC : O(Number of nodes)   SC: O(maximum height of the tree)(auxulary stack space)
    int find(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        
        int lv = max(0,find(root->left, ans));
        int rv = max(0,find(root->right, ans));
        
        int sum = root->val + lv+rv;
        ans = max(sum ,ans);
        return root->val + max(lv, rv);
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans =-1e5;
        find(root, ans);
        return ans;
    }
};
