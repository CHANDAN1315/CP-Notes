// poblem link https://leetcode.com/problems/combination-sum/
#define fo(i,0,n)  for(int i =0; i<=n; i++)

void solve(vector<int> &a, vector<int> &ds, int i, int k, int n) {

    if (i == a.size() ) {
        if (k == 0) {
            fo(i, 0, ds.size()-1) cout << ds[i] << " ";
            cout << endl;
        }
        return;
    }
  
    if (a[i] <= k) {
        // k -= a[i];
        ds.pb(a[i]);
        solve(a, ds, i, k - a[i], n);
        ds.pop_back();

    }

    solve(a, ds, i + 1, k, n);


}
int main(){
   int n; cin >> n;
   int k ; cin >> k;
   vector<int> a(n), ds;
   int sum = 0;
   for (int i = 0; i < n; i++) {
       cin >> a[i];
   }
        // debug(a)
  solve(a, ds, 0, k, n);
  
  return 0;
}
