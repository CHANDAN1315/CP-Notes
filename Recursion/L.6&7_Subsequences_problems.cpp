/*Lecture 6 and 7 */
/*Recursion on subsequences*/

/* note :-
    subsequences - A contigouse and non-contigouse sequence which follow the order.
                    eg- arr = {3,1,2}
                    3,2,1 is not a s.s
                    but 3,1,2 and 3,2 are
*/

/*  1.Print the all the subsequence of the given array */


// itterarive way is using bit masking
//Recursive code using pick and not pick concept

// T.C -> (2^n * n(printing the arr every time))
// S.C -> (n)- i.e depth of the recursion call.

void subsequence(int i, vector<int> &a, int v[], int n) {

    if (i >= n) {
        for (auto i : a) {
            cout << i << " ";
        }
        return;
    }
    // Adding the element(pick condition).
    a.emplace_back(v[i]);
    // calling the next function for the next elements.
    subsequence(i + 1, a, v, n);
    a.pop_back();

    // not pick condition.
    subsequence(i + 1, a, v, n);
}


/*  2. Print all the subsequnce have the sum as k(given) */

void sum_equal_to_k(int ind , int s, vector<int> &v, int a[] , int k, int n ) {

    if (ind == n) {
        if (s == k) {
            for (auto it : v) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }


    // taking the element
    v.emplace_back(a[ind]);
    s += a[ind];
    // calling the next function
    sum_equal_to_k(ind + 1, s , v, a, k, n);

    v.pop_back();
    s -= a[ind];

    sum_equal_to_k(ind + 1, s, v, a, k, n);
}

