
// Memoziation : TC : O(n*tar)  SC: O(n*tar) + O(n)/auxlary space
int f(int ind , vector<int> &num, int tar, vector<vector<int>> &dp){
    if(tar == 0) return 1;
    if(ind == 0){
      return (num[ind] == tar);
    }
    if(dp[ind][tar] != -1) return dp[ind][tar];
    int pick = 0;
    if(tar>= num[ind]) pick = f(ind-1, num ,tar - num[ind],dp );
    int not_pick = f(ind-1, num, tar,dp);
    
    return dp[ind][tar] = (pick + not_pick);
    
}

int findWays(vector<int> &num, int tar)
{
     // we know that for generating sub set we use pick and not pick techini    que
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1, num, tar, dp);
}


// Tabulation :  TC : O(n*tar)  SC: O(n*tar) 
int findWays(vector<int> &num, int tar)
{
     // we know that for generating sub set we use pick and not pick techini    que
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1));
//     return f(n-1, num, tar, dp);
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    if(num[0] <= tar) dp[0][num[0]] = 1;
    for(int ind =1; ind <n; ind++){
        for(int sum = 0;sum <=tar; sum++){
             int pick =0;
             if(sum >= num[ind]) pick = dp[ind-1][sum - num[ind]];
             int not_pick = dp[ind-1][sum];
            
            dp[ind][sum] = pick + not_pick;
        }
    }
    return dp[n-1][tar];
   
}
