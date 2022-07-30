//link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // if we get null then mark it as #
        
        /*
            note: if we use res += node->val insted of res.append(node->val) then it give MLE
            reason: every time '+=' executed it will create a copy of res
            
        */
        if(root == NULL) return "";
        
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0; i<sz; i++){
                auto node = q.front();
                q.pop();
                
                if(node == NULL){
                    res.append("#,");
                }
                else {
                    res.append(to_string(node->val)+',');
                }
                
                if(node != NULL){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,','); // store the first element of s in str after saprator hit ','
        
        TreeNode* root = new TreeNode(stoi(str)); //created a root node with value str
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
