// Problem link: https://leetcode.com/problems/diameter-of-binary-tree/
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
      // N -> number of nodes
    // Brute force solution : TC: O(N^2)    SC:  O(number of nodes)
  /*
    Approch : In this approch we went to each subtree and get its max depth of it using the previous problem 
    Now for every maximum depth we store the maximum sum of left and the right node of that subtree and which 
    ever will gives us the max val we store it in ans.
  
  */
    int ans =0;   
   int find(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = find(root-> left);
        int rh = find(root-> right);
        
        return max(lh, rh)+1;   
    }
    
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        int lh = find(root->left);
        int rh = find(root->right);
                
        ans = max(ans, lh+rh);
        
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        
        return ans;
        
        
        
        // Every time we need to chose the longest side of that nood.
        
//     }
        
        // Better sol :  TC: O(number of nodes)     SC(number of nodes)
        int find(TreeNode* root, int& sum ){
            if(root == NULL) return 0;
            
            int lh = find(root->left, sum);
            int rh = find(root->right, sum);
            
            sum = max(sum , lh+rh);
            
            return 1+ max(lh, rh);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            
            if(root == NULL) return 0;
            int sum = 0;
            find(root, sum);
            return sum;   
            
        }

    
};
