/*Lecture 5 */
/*Multiple Recursion calls */

// Find the n-th Fibonacci number.

// itterative way
void n_th_fibonacci() {
    int n; cin >> n;
    vector<int> a(n);

    a[0] = 0 , a[1] = 1;
    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    cout << a[n - 1];
}


//Recursive way
int n_th_fibonacci(int n) {

    if (n <= 1) return n;

    int last = n_th_fibonacci(n - 1);
    int slast = n_th_fibonacci(n - 2);
    return last + slast;

}

// note the T.C = 2^n()(nearly not exact)
// type is epoential T.C. 
