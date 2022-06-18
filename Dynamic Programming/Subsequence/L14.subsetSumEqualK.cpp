// Memoziation : 
bool f(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    
    if(k == 0) return true;
    if(n == 0) return ((k - arr[n]) == 0);
    if(dp[n][k] != -1) return dp[n][k];
    bool pick = false;
    if(k >= arr[n]) pick = f(n-1, k - arr[n], arr, dp);
    bool not_pick = f(n-1, k, arr, dp);
    
    return dp[n][k] = (pick | not_pick);
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n ,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
    
}
