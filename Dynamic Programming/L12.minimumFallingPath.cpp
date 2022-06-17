class Solution {
public:
    // Method 1 Memoziation   TC : O(n*n)   SC O(n-1) + O(n-1) + O(n*n)
    int f (int n, vector<vector<int>>& mat, int col, vector<vector<int>>& dp){
        
        if(col < 0 || col >= mat[0].size()) return 1e8;
        
        if(n == 0 ) return mat[0][col];
        
        if(dp[n][col] != -1) return dp[n][col];
        
        int up_r = f(n-1, mat, col+1,dp);
        int up = f(n-1, mat, col,dp);
        int up_l = f(n-1, mat, col-1,dp);
        // cout <<up<<" "<<up_l<<" "<<up_r<<endl;
        
        return dp[n][col] = mat[n][col] + min(up, min(up_l,up_r));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans =INT_MAX;
        int n = matrix.size();
      
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int col=0; col<n; col++){
            
            int sum = f(n-1, matrix, col,dp);
            ans = min(ans, sum);
        }
        return ans;
    }
  
  
  
  
  
    // Tabulation : TC : O(n*n)   SC : O(n*n)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        // base to intilize the dp
        
        for(int i =0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        
        for(int i = n-2; i>=0; i--){
            for(int j =0; j<n; j++){
                int dwn_r = INT_MAX,dwn_l =INT_MAX;
                int dwn = dp[i+1][j];
                if(j<n-1) dwn_r = dp[i+1][j+1];
                if(j > 0) dwn_l = dp[i+1][j-1];
                
                dp[i][j] = matrix[i][j] + min({dwn,dwn_l, dwn_r});
            }
        }
        int ans = INT_MAX;
        for(int i =0; i<n; i++){
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
 
};
