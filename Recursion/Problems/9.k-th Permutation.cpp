
void solve() {

    // 1 2 3

    int n, k; cin >> n >> k;
    vector<int> fact;
    int f = 1;
    for (int i = 1; i < n; i++) {
        f = f * i;
        fact.pb(i);
    }
    fact.pb(n);

    string ans = "";
    debug(fact)
    while (true) {
        ans = ans + to_string(fact[k / f]);
        fact.erase(fact.begin() + k / f);
        if (fact.size() == 0) {
            break;
        }
        k = k % f;
        f = f / fact.size();
    }
    cout << ans;





    // how to find the factorial of a number

    /*
        n = 4 and k = 17
        1 2 3 4 -->
        4! = 24 = 24/4 = 6/3 = 2/2 = 1/1 = 1;
        1 - 6
        2 - 6
        3 - 6
        4 - 6


    */

}
