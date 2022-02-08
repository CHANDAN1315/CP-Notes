/*Lecture 1 : Introduction*/

/*
    ways to solve dp problems :-
    
    1) Memoization  :- Top-Down DP
    2) Tabulation   :- Bottome-Up DP
    


    memoization  -> tabulation -> space optimization


    note : whenever we solve the same sub problem again and again the DP comes into play
           Eg in fabonachi number we compute the previous number again and again in the other banches
           of the recursion tree.

            f(5) = f(4) + f(3)
                    f(4) = f(3) + f(2)
                    f(3) = f(2) + f(1)
                    f(2) = f(1) + f(0) -> base case

            f(3) = f(2) + f(1)  ->    note:- this thing is call overlaping sub problem
                    f(2) = f(1) + f(0) -> base case

            for more understanding see the recursion tree for febonachi
*/
// (Memoziation method) for febonachi number
//TC - O(n)  and  SC - O(n)(recursion stack) +  O(n)

int f(int n , vector<int> &dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = f(n - 2, dp) + f(n - 1, dp);
}

int main() {
    int n ; cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);


    return 0;
}


// (Tabulation method)
// in this method we reduce the recursion stack space and only use only the vector space
// TC - O(n)  SC - o(n)
int f (int n , vector<int> &dp) {
    dp[0] = 0; dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    int n ; cin >>n;
    vector<int> dp(n+1,-1);
    cout<<dp[n];
}


// (space optimeization)
//TC - O(n) 

int main(){
    int n; cin>>n;
    int pre1 = 0;
    int pre2 = 1;

    for(int i =2 ; i<= n; i++){
        int curi = pre2 + pre1;

        pre1 = pre2;
        pre2 = curi;
    }
    cout <<pre2;
}
