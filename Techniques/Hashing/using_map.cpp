// https://codeforces.com/contest/1702/problem/C
// Implementation.
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
 
