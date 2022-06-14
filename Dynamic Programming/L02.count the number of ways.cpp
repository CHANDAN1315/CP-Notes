// L2. Climebing stairs
/*
    que: - count the number of ways to reach the nth stare by using 1 or 2 step at a time.


    note1 :- how do you find that the que is asking for a dp solution
            1) if the problem is asking to find number of ways.
            2) find the maximum and minimum way
            3) try all possible way to solve the poblem kind of a thing then we apply dp for sure
            4) counting poblems.


    note2 :- how to form the recurance relation for dp
            1) Try to represent the poblem in terms of index
            2) Do all possible staffs on that index according to the poblem statement
            3) count all ways -> sum of all the possible ways
            4) if the problem about find the minimum/maximum then ->  min/max(off all the stuffs)


*/

// This porblem is similler to the febonachi question
// steps : 1. try to find the base case and edge case
// recursive form
int f(int n) {
    if (n == 0 || n == 1) return n;

    int left = f(n - 1);
    int right = f(n - 2);

    return left + right;
}

// memoziation form
int f(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = f(n - 2, dp) + f(n - 1, dp);


}

int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
}
