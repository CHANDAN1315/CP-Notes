class Solution {
public:
  
    // Method 1 : Momoziation    TC: O(n*m)   SC: O(n-1) + o(m-1) +O(n*m)
  
    int f (int n , int m , vector<vector<int>> &vec, vector<vector<int>> &dp){
        if(n == 0 and m == 0) {
            return vec[n][m];
        }
        if(n < 0 or m <0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int sum = vec[n][m];
        int left = INT_MAX, up = INT_MAX;
        
        if(m > 0) left =  f(n , m-1, vec,dp);
        if(n > 0) up = f(n-1 , m, vec,dp);
         
        return dp[n][m] = sum + min(left, up);
        
   }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return f(n-1,m-1,vec,dp);
    }
 
  
  
    // Method 2 : Tabulation: TC O(n*m)  SC O(n*m)
  
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        // dp[0][0] = vec[0][0];
        
        for(int i =0;i<n; i++){
            for(int j =0; j<m; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = grid[0][0];
                    continue;
                }
                int left =INT_MAX, up =INT_MAX;
                
                if(j >0) left = dp[i][j-1];
                if(i > 0) up= dp[i-1][j];
                int sum = grid[i][j];
                // cout << sum;
                dp[i][j] = min(left, up)+sum;
            }
        }
        return dp[n-1][m-1];
    }
};
