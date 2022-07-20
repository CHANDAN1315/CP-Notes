// Problem link : https://www.interviewbit.com/problems/path-to-given-node/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TC : O(N)   SC: O(height of tree)
 bool check(TreeNode* root, int B, vector<int>& ans){
     if(root == NULL) return false;
     bool x = false, y = false;
     ans.push_back(root->val);
     if(root->val == B) return true;
     
     if(check(root->left, B, ans) || check(root->right, B, ans)) return true;
    //  if(x == false) ans.pop_back();
    ans.pop_back();
     return false;
    //  return (x||y);
      
 }
 
vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> ans;
    if(root == NULL) return ans;
    
    check(root, B, ans);
    
    return ans;
}
