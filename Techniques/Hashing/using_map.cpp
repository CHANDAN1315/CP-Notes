// https://codeforces.com/contest/1702/problem/C
// Implementation. Fail in TC : 5
void solve() {
 
    int n, k; cin>>n>>k;
    vector<int> ar(n);
    map<int, vector<int>> mpp;
    for(int i =0; i<n; i++){
        cin>>ar[i];
        mpp[ar[i]].push_back(i);
    }

  while(k--){
        int x , y; cin >>x>>y;
        vector<int> l1 = mpp[x];
        vector<int> l2 = mpp[y];
        bool f =0;
        for(int i =0; i<l1.size(); i++){
            for(int j =0; j<l2.size(); j++){
                if(l1[i] < l2[j]){
                    f =1;
                }
            }
        }
        cout <<(f ? yes : no)<<endl;
    }
}

// Optimized code.
void solve() {

    int n, k; cin >> n >> k;

    map<int, int> l , h;
    for (int i = 0; i < n; i++) {
        int x ; cin >> x;
        if (l.find(x) == l.end()) {
            l[x] = i;
            h[x] = i;
        }
        else h[x] = i;
    }

    while(k--){
        int a , b; cin >>a>>b;
        if(l.find(a) == l.end() or l.find(b) == l.end()){
            cout <<no<<endl;
            continue;
        }
        if(l[a] < h[b]){
            cout <<yes<<endl;
        }
        else cout <<no<<endl;
    }

}
