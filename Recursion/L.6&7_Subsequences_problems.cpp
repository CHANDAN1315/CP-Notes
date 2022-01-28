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


/*  2. Print all the subsequnce that have the sum equals to k(given) */

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

// IF you are asked to print only one answer which is equal to k (simillar to que 2)
bool sum_equal_to_k(int ind , int s, vector<int> &v, int a[] , int k, int n ) {

    if (ind == n) {
        // condition satisfied
        if (s == k) {
            for (auto it : v) cout << it << " ";
            cout << endl;
            return true;
        }
        // Condition not satisfied
        return false;
    }


    // taking the element or pick condition
    v.emplace_back(a[ind]);
    s += a[ind];
    // calling the next function
    /*importan trick used for printing only one answer use of if condintion to use the recursion calls*/
    if (sum_equal_to_k(ind + 1, s , v, a, k, n) == true) {
        return true;
    }

    v.pop_back();
    s -= a[ind];
    //not pick condition
    if (sum_equal_to_k(ind + 1, s, v, a, k, n) == true) {
        return true;
    }

    return false ;
}


/*3. Print the count how many subsequence have sum equal to k*/
// T.C -> 2^n
int countOf_sum_equal_to_k(int ind , int sum, int a[] , int k, int n ) {

    if(sum > k) return 0; // this case only valid if the elements are (+ve)int.//it will save some recursion calls
    if (ind == n) {
        if(sum == k) return 1;
        else return 0;
    }


    // taking the element
    sum += a[ind];
    // calling the next function
    int l = countOfsum_equal_to_k(ind + 1, sum , a, k, n);

    sum -= a[ind];

    int r = countOfsum_equal_to_k(ind + 1, sum, a, k, n);

    return l+r;

    // future related problem is n- queen
}
