// problem link : https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
/*
  hint : work on pick and not pick condition of subsequence problem of recursion condition.

*/  

// Recursive solution.
// tc : 2^n   sc: n
int subsequence(int ind , vector<int> &arr) {
    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;

    int pick = arr[ind] + subsequence(ind - 2, arr);
    int not_pick = 0 + subsequence(ind - 1, arr);

    return max(pick, not_pick);
}


int main () {

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << subsequence(n-1, arr);
  
  return 0;
}


// Mimozation solution
// tc : n  sc : n + n
int subsequence(int ind , vector<int> &arr, vector<int> &dp) {
    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];
  
    int pick = arr[ind] + subsequence(ind - 2, arr, dp);
    int not_pick = 0 + subsequence(ind - 1, arr, dp);

    return dp[ind] = max(pick, not_pick);
}


int main () {

    int n; cin >> n;
    vector<int> arr(n);
    vector<int> dp(n,-1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << subsequence(n-1, arr, dp);
  
  return 0;
}


// Tabulationint
// tc : n  sc : n
f(int n , vector<int> &arr) {
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1) pick += dp[i - 2];
        int not_pick = dp[i - 1];

        dp[i] = max(pick, not_pick);
        // deb(dp)
    }
    deb(dp)
    return dp[n - 1];
}
void solve() {

    int n; cin >> n;
    vector<int> arr(n);
    // vector<int> dp(n, -1);
    // deb(dp)
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << f(n, arr);
}

