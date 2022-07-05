// Problem link : https://leetcode.com/problems/balanced-binary-tree/

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
    
    /*
        Approch : In this problem we are given a condition that if the height of the left and right subtree is differ by > 1 then it is not a blanced binary tree.
        
        So then problem boildown to finding the height of the left and the right subtree and check their difference.
    
    */
    //
    // Brute approch : TC : O(Number of nodes)^2    SC: O(Auxlary stack space)
    int find(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int lh =  find(root->left);
        int rh = find(root -> right);
        
        return 1+max(lh, rh);
        
    }
    
    
    bool isBalanced(TreeNode* root)
    {
        if (root == NULL) return 1;
        
        int lh = find(root->left);
        int rh = find(root->right);
        
        // if(abs(lh - rh) > 1) return false;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        return(abs(lh - rh) <= 1 and left and right); 
        
    }
  
  
  
    // Better Approch :  TC : O(number of nodes)   SC : O(Auxulary stack space).
    int find(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = find(root-> left);
        int rh = find(root-> right);
        
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh- rh) > 1) return -1;
        
        return max(lh, rh)+1;
        
    }
    
    bool isBalanced(TreeNode* root){
        return (find(root) == -1 ? false : true);
    }

  
    
};
