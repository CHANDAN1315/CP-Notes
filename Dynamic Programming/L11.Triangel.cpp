class Solution {
public:
    
 // Method 1 : TC O(n*n)   SC O(n*n) + O(n-1) + O(n-1)
    int f(int n , int ind , vector<vector<int>> &tr, vector<vector<int>> &dp){
        int leng = tr.size();
        
        if(n == leng){
            return 0;
        }
        if(dp[n][ind] != -1) return dp[n][ind];
        
        int lf = tr[n][ind] + f(n+1, ind, tr, dp);
        int rf = tr[n][ind] + f(n+1, ind+1, tr,dp);
        
        return dp[n][ind] = min(lf,rf);
    }
    
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        int m = tr[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,tr,dp);
    }
  

  
  
  
// Method 2 : TC : O(n*n)  SC: O(n*n)    (Striver soln)
    
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i = 0; i<n; i++){
            dp[n-1][i] = tr[n-1][i];
        }
        
        for(int i =n-2; i>=0; i--){
            for(int j =i; j>=0; j--){
                int down = tr[i][j] + dp[i+1][j];
                int downn = tr[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, downn);
            }
        }
        
        return dp[0][0];    
    }

  

  
  
// Method 2 : TC : O(n*n)  SC: O(n*n)  
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        int m = tr[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        dp[0][0] = tr[0][0];
        for(int i=1; i<n; i++){
            for(int j = 0; j<=i; j++){
                int up = INT_MAX; int left = INT_MAX;
                
                if(i-1 >= j) up = tr[i][j] + dp[i-1][j];
                if(j > 0) left = tr[i][j] + dp[i-1][j-1];
                
                dp[i][j] = min(left, up);
                
            }
        }
        int ans =  dp[n-1][0];
        for(int i =1; i<n; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
            
    }
       
};
