
// Brute solution T.C - 2^n *k*log(number of times ds got inserted)
void solve(vector<int> &a, vector<int> ds, int target, int i, int n, set<vector<int>> &ans) {

    if (target == 0) {
        ans.insert(ds);
        return;
    }

    if (target < 0 || i == n ) return;

    ds.pb(a[i]);
    solve(a, ds, target - a[i], i + 1, n, ans);

    ds.pop_back();
    solve(a, ds, target, i + 1, n, ans); // not pick condition

}
int main(){
        int n; cin >> n;
        int target; cin >> target;
        vector<int> a(n), ds;
        read(a);
        // debug(a)
        set<vector<int>> st;
        solve(a, ds, target, 0, n, st);

        for (auto i : st) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
  
  return 0;
}



// Optimal solution  TC : 2^n *
void solve(vector<int> &a, vector<int> ds, int target, int ind, int n, vector<vector<int>> &ans) {

    if (target == 0) {
        ans.pb(ds);
        return;
    }
    for (int j = ind; j < a.size(); j++) {
        if (a[j] == a[j - 1] and j > ind) continue;
        if (a[j] > target) break;
        
        ds.pb(a[j]);
        solve(a, ds, target - a[j], j + 1, n, ans);
        ds.pop_back(); 
    }

}
int main(){
        int n; cin >> n;
        int target; cin >> target;
        vector<int> a(n), ds;
        read(a);
        sort(all(a));
        vector<vector<int>> ans;
        solve(a, ds, target, 0, n, ans);
        return 0;
}
