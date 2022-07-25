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

// Brute solution  TC: O(n)   SC O(height of BT i.e log(n))
class Solution {
public:
  int countNodes(TreeNode* root){
      if(root == NULL) return 0;
      int lft =0, rgt =0;
      if(root->left){
          lft = countNodes(root->left);
      }
      if(root->right){
          rgt = countNodes(root->right);
      }
      return lft+rgt+1;
  }
};


// Optimal solution : TC: o(log(n))    SC: O(log(n))

class Solution {
public:
        
    int findleft(TreeNode* node){
        int height =0;
        while(node){
            height++;
            node= node->left;
        }
        return height;
    }
    
    int findright(TreeNode* node){
        int height =0;
        while(node){
            height++;
            node= node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int lft = findleft(root);
        int rgt = findright(root);
        
        
        if(lft == rgt) return (1<<lft)-1;
        
        return (1+countNodes(root->left) + countNodes(root->right));
  
    }

    
};
