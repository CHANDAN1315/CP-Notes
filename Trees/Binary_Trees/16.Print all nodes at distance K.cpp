// Problem link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TC: O(n) + O(n) + log(n)   SC:O(n) + O(n) + O(n)
class Solution {
public:
    
    void makeParent(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &mpp, TreeNode* target ){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            if(current->left){
                mpp[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                mpp[current->right] = current;
                q.push(current-> right);
            }
            
        }
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        makeParent(root,mpp,target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int cur_level =0;
        while(!q.empty()){
            int sz = q.size();
            if(cur_level++ == k) break;
            for(int i =0; i<sz; i++){
                auto node = q.front();
                q.pop();
                if(node->left and !(visited[node->left])){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right and !(visited[node->right])){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(mpp[node] and !(visited[mpp[node]])){
                    q.push(mpp[node]);
                    visited[mpp[node]] = true;
                }
            }
        }
        
        vector<int> result;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;

    }
};
