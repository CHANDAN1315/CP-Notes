/*1. Count the number of divisor of n */

// T.C -> O(n)
int number_of_divisors(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cnt++;
	}
	return (n == 1 ? 1 : cnt);
	/*note -> if cnt = 2 or 1 then the number is prime other wise not prime*/
}



// T.C -> sqrt(n)
int number_of_divisors(int n) {
	int cnt = 0;
	for (int i = 1; i * i <= n; i++) {

		if (n % i == 0) cnt++;

		if (n / i != i) cnt++;
	}
	return (n == 1 ? 1 : cnt);
	/*
	  note1 -> if cnt = 2 or 1 then the number is prime other wise not prime

	  note2 -> we can also use this to find the number of divisor of each number till n use extra
	  			for loop of n to print or store it in vector.
	  			T.C -> n*(sqrt(n))
	*/
}


//2.Find the count of primes of each number till n.
// T.C -> n*log(n) which is better than n*sqrt(n)
int number_of_divisors_of_each_number(int n ) {
	vector<int> div(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			div[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << div[i] << endl;
	}

}




/*  Seive of Eratosthenes
	->	used to store number of primes till n
	->	give us idea how many primes are there in between range l to r
	-> T.C -> n*log(log(n)) *aprox
*/

const int N = 100001;   // change the const value up to 10^6
vector<int> primes;        // it stores prime numbers
bool seive[N];         // it store that the number is a prime (i.e 1) or not (i.e 0)

void create_seive() {
    memset(seive, true, N);
    for (int i = 2; i <= N; i++) {
        if (seive[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= N; j += i) {
                if (seive[j]) {
                    seive[j] = 0;
                }
            }
        }
    }
}




/*  (Segmented Seive)
    1.given a range l to r, how many primes are there in that range
        Constraints ->  1 <= l <= r <= 10^10
                    l - r <= 10^4


    note :- if (r-l) > 10^4 then this algo does't work try to implement using maths and
            observations.
            e.g - 10^7 - 10^6 (not valid constraint)

    steps :-
            1. Find all primes till (r).
            2. Create an (hash) array of difference (r - l) .
            3. Mark all multiples of primes.
            4.Itterate and check which are mark 1 then it is prime.

    e.g - l = 110 and r = 131

*/
const int N = 100001;   // change the const value up to 10^6
vector<int> primes;        // it stores prime numbers
bool seive[N];         // it store that the number is a prime (i.e 1) or not (i.e 0)

void create_seive() {
    memset(seive, true, N);
    for (int i = 2; i <= N; i++) {
        if (seive[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= N; j += i) {
                if (seive[j]) {
                    seive[j] = 0;
                }
            }
        }
    }
}

void SegmentedSeive() {
    create_seive();
    int l , r; cin >> l >> r;

    // create dummy array of difference size and everyone marked as true
    int dummy[r - l + 1];
    for (int i = 0 ; i < r - l + 1; i++) dummy[i] = 1;

    // mark all multiples of primes
    for (int i = 0; i < r; i++) {

        int firstMultiple = (l / pr) * pr;
        if (l % pr) firstMultiple += pr;

        for (int j = max(firstMultiple, pr * pr); j <= r; j += pr ) {
            dummy[j - l] = 0;
        }
    }

    // iterate and count primes
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (dummy[i - l] == 1) cnt++;
    }
    cout << cnt;

}



