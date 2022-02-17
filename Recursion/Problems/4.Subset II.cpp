// problem link : https://leetcode.com/problems/subsets-ii/
// TC :  
void solve(vector<int> &a, vector<int> ds, int ind ) {

    for (auto i : ds) cout << i << " ";
    cout << endl;
    if (ind == a.size()) return;

    for (int i = ind; i < a.size(); i++) {

        if (a[i] == a[i - 1] and i > ind) continue;

        ds.pb(a[i]);
        solve(a, ds, i + 1);
        ds.pop_back();
        // solve(a,ds,i+1);
    }
}
int main(){

    int n ; cin >> n;
    vector<int> a(n), ds;
    for (auto &i : a) cin >> i;

    solve(a, ds, 0);
    cout << endl;
    return 0;
}
