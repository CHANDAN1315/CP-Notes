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
vector<int> pre;        // it stores prime number
bool primes[N] = {0};   // it store that the number is a prime (i.e 0) or not (i.e 1) 

void seive() {
    for (int i = 2; i <= N; i++) {
        if (primes[i] == 0) {
            pre.pb(i);
            for (int j = i * i; j <= N; j += i) {
                if (primes[j] == 0) {
                    primes[j] = 1;
                }
            }
        }
    }

}

// que -> how many prime number are between l to r
// hint -> use a for loop between l to r and check the which number is prime or not  


