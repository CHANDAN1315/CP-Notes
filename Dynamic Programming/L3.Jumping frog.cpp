/*L3. Frog Jump*/

/*  que:
    https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=
    youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

/*soln
    case where greedy doesnt work eg : 30 10 60 10 60 50
    so we need to find all possible way to go from i =0 to i =n.

*/
// Recursion approch
/*
    approch : first make the recursion tree and try to understant the flow of the code
*/

// vector a = height
int f(int n , vector<int> &a) {

    if (n == 0) return 0 ;

    int left = f(n - 1, a) + abs(a[n] - a[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = f(n - 2, a) + abs(a[n] - a[n - 2]);

    return min(left, right);
}

void solve() {
    int n ; cin >> n;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << f(n - 1, a);

}


// Memoziation

int f(int n , vector<int> &a, vector<int>&dp) {

    if (n == 0) return 0 ;

    if (dp[n] != -1) return dp[n];

    int left = f(n - 1, a, dp) + abs(a[n] - a[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = f(n - 2, a, dp) + abs(a[n] - a[n - 2]);

    return dp[n] = min(left, right);
}

void solve() {
    int n ; cin >> n;
    int ans = 0;
    vector<int> a(n), dp(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << f(n - 1, a, dp);

}


// Tabulation solution
/*
    steps to approch tabulation method

    1) create dp[n+1] vector .
    2) look at the base case and make the first step using it for e/g dp[0] = 0
    3) find out up how much you want to go and fill the table
    4)
*/



void solve() {
    int n ; cin >> n;
    int ans = 0;
    vector<int> a(n), dp(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int left = d[i - 1] + abs(a[i] - a[i - 1]);
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i - 2] + abs(a[i] - a[i - 2]);
        }

        dp[i] = min(left, right);
    }
    cout << dp[n - 1];
}


// Space optimization
/*
    approch : create the index and give them intial values
                0         1       2        3      4 5 .... n-1
    st1        dp[i-2]  dp[i-1]  dp[i]

    st2                  dp[i-2] = d[i-1]  dp[i-1] = dp[i]  dp[i] = (relation between dp[i-1] and dp[i-2]).


*/

void solve() {
    int n ; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++) {

        int left = prev + abs(a[i] - a[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(a[i] - a[i - 2]);

        curi = min(left , right);

        prev2 = prev;
        prev = curi;

    }
    cout <<prev;


}


// MY expremental method not much tested
void solve() {
    int n ; cin >> n;
    vector<int> a(n);
    read(a);
    int ans =0;
    for (int i = 2; i < n; i++) {

        int ans1 = abs(a[i] - a[i-1]);
        int ans2 = abs(a[i] - a[i-2]);

        ans += min(ans1,ans2);
        
    }
    cout<<ans;


}
