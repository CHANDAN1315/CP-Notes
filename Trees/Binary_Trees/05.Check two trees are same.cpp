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
    // TC : O(n)    SC: o(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // For this problem sum1 == sum2 and structure should also same 
        // if(p == NULL and q == NULL) return true;
        if(p == NULL or q == NULL) return (q==p);
        
        bool lt = isSameTree(p->left, q->left);
        bool rt = isSameTree(p->right , q->right);
        
        if(p->val == q->val and lt&rt) return true;
        else return false;
        
    }
};
