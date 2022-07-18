/* Problem link : https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;
                utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos
*/
// n : number of nodes
// TC : O( n*log(n))   SC : O(n)
vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }
