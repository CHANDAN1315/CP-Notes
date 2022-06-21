
// Memoziation :  TC : O(n) + O(n*sum/2+1)    SC: O(n*sum/2) + O(n)
bool f(int n , int k , vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(n == 0) return (k == arr[0]);
    if(dp[n][k] != -1) return dp[n][k];
    bool pick = false;
    if(arr[n] <= k) pick = f(n-1, k- arr[n], arr, dp);
    bool not_pick = f(n-1, k, arr, dp);
    
    return dp[n][k] = (pick | not_pick);    
}

bool canPartition(vector<int> &arr, int n){    
    int sum =0;
    for(auto i : arr) sum += i;
    if(sum&1) return false;
    else sum /= 2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return f(n-1,sum,arr,dp);
    
}


//Method 2:  Tabulation  TC: O(n*m)   SC: O(n*k)
bool canPartition(vector<int> &arr, int n) {
    int sum =0;
    for(auto i : arr) sum += i;
    if(sum&1) return false;
    else sum /= 2;
  
    vector<vector<bool>> dp(n, vector<bool>(sum+1,0));
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int i =1; i<n; i++){
        for(int target = 1; target<=sum; target++){
            
            bool pick = false;
            if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
            bool not_pick = dp[i-1][target];
          
            dp[i][target] = (pick | not_pick); 
        }
    }
    return dp[n-1][sum];
    
}
