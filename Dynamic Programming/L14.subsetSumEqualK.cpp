
// Method 1: Memoziation :  TC : O(n*k)  SC: O(n*k) + O(n-1)
bool f(int n , int k , vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(n == 0) return (k == arr[0]);
    if(dp[n][k] != -1) return dp[n][k];
    bool pick = false;
    if(arr[n] <= k) pick = f(n-1, k- arr[n], arr, dp);
    bool not_pick = f(n-1, k, arr, dp);
    
    return dp[n][k] = (pick | not_pick);    
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return f(n-1 , k , arr, dp);
    
}

//Method 2:  Tabulation  TC: O(n*m)   SC: O(n*k)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1,0));
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] < k) dp[0][arr[0]] = true;
    for(int i =1; i<n; i++){
        for(int target = 1; target<=k; target++){
            bool pick = false;
            if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
            bool not_pick = dp[i-1][target];
            dp[i][target] = (pick | not_pick); 
        }
    }
    return dp[n-1][k];
    
}






