// Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/

// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };

class Solution {
public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // we can apply dfs in it 
        if(root == NULL) return new TreeNode(val);
        TreeNode* cur = root;
        while(true){
            if(val < cur->val){
                
                if(cur->left != NULL) cur = cur->left;
                else{
                    // note: cur->left point to the null point and we use the pointer and insert the node where it point in the root
                    cur->left = new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->right !=  NULL) cur = cur->right;
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            
        }
        return root;
        
    }

};
