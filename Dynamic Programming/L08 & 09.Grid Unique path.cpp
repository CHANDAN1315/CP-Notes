class Solution {
public:
  
 // Method 1 . Recursive Solution    TC : 2^n*m    SC: Recursion stack space 
     int uniquePaths(int m, int n) {
       if(m== 1 || n==1) {
            return 1;
        }
        if(m<=0 || n <=0) return 0;
        
        int up = uniquePaths(m-1,n);
        int left = uniquePaths(m,n-1);
        
        return up + left;
   

       
// Method 2 : Memoziation solution   TC : O(n*m)  SC: O(n-1) + O(m-1) *O(n*m) 
int f (int m, int n, vector<vector<int>> &dp){
        if(m== 0 && n==0) {
            return 1;
        }
        if(m<0 || n <0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int up = f(m-1, n, dp);
        int left = f(m, n-1, dp);
        dp[m][n] = up + left;
        
        return  dp[m][n];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int x = f(m-1,n-1,dp);
        cout<<x;
        return x;
    }
  
 
// Method 3 tabulation: O(n*m) S.C -O(n*m)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // in tabulation base case is the stating point
        
        // dp[0][0] = 1;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(i==0 and j ==0){
                    dp[0][0] = 1;
                    continue;
                }
                int up =0;
                int left =0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                
                dp[i][j] = up + left;
                
            }
        }
        return dp[m-1][n-1];
    }
    
};
