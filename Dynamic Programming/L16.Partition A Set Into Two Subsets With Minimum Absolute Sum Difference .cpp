

// Time is similler to L14 + O(totalSum.leng())
int minSubsetSumDifference(vector<int>& arr, int n)
{    
    int totalSum = 0;
    for(auto i : arr) totalSum += i;
    
    vector<vector<bool>> dp(n, vector<bool>(totalSum+1,0));
  
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= totalSum) dp[0][arr[0]] = true;
    for(int i =1; i<n; i++){
        for(int target = 1; target<=totalSum; target++){
            bool pick = false;
            if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
            bool not_pick = dp[i-1][target];
            dp[i][target] = (pick | not_pick); 
        }
    }
    int ans = 1e9;
    for(int i = 0; i<=totalSum; i++){
        if(dp[n-1][i] == true){
            ans = min(ans, abs(totalSum - i - i));
        }
    }
    return ans ;
}
