/* A C++ program to answer queries to check whether
the substrings are palindrome or not efficiently */
#include <bits/stdc++.h>
using namespace std;

#define p 101
#define MOD 1000000007

// Structure to represent a query. A query consists
// of (L, R) and we have to answer whether the substring
// from index-L to R is a palindrome or not
struct Query {
	int L, R;
};

// A function to check if a string str is palindrome
// in the range L to R
bool isPalindrome(string str, int L, int R)
{
	// Keep comparing characters while they are same
	while (R > L)
		if (str[L++] != str[R--])
			return (false);
	return (true);
}

// A Function to find pow (base, exponent) % MOD
// in log (exponent) time
unsigned long long int modPow(
	unsigned long long int base,
	unsigned long long int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	unsigned long long int temp = modPow(base, exponent / 2);

	if (exponent % 2 == 0)
		return (temp % MOD * temp % MOD) % MOD;
	else
		return (((temp % MOD * temp % MOD) % MOD)
				* base % MOD)
			% MOD;
}

// A Function to calculate Modulo Multiplicative Inverse of 'n'
unsigned long long int findMMI(unsigned long long int n)
{
	return modPow(n, MOD - 2);
}

// A Function to calculate the prefix hash
void computePrefixHash(
	string str, int n,
	unsigned long long int prefix[],
	unsigned long long int power[])
{
	prefix[0] = 0;
	prefix[1] = str[0];

	for (int i = 2; i <= n; i++)
		prefix[i] = (prefix[i - 1] % MOD
					+ (str[i - 1] % MOD
						* power[i - 1] % MOD)
						% MOD)
					% MOD;

	return;
}

// A Function to calculate the suffix hash
// Suffix hash is nothing but the prefix hash of
// the reversed string
void computeSuffixHash(
	string str, int n,
	unsigned long long int suffix[],
	unsigned long long int power[])
{
	suffix[0] = 0;
	suffix[1] = str[n - 1];

	for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++)
		suffix[j] = (suffix[j - 1] % MOD
					+ (str[i] % MOD
						* power[j - 1] % MOD)
						% MOD)
					% MOD;
	return;
}

// A Function to answer the Queries
void queryResults(string str, Query q[], int m, int n,
				unsigned long long int prefix[],
				unsigned long long int suffix[],
				unsigned long long int power[])
{
	for (int i = 0; i <= m - 1; i++) {
		int L = q[i].L;
		int R = q[i].R;

		// Hash Value of Substring [L, R]
		unsigned long long hash_LR
			= ((prefix[R + 1] - prefix[L] + MOD) % MOD
			* findMMI(power[L]) % MOD)
			% MOD;

		// Reverse Hash Value of Substring [L, R]
		unsigned long long reverse_hash_LR
			= ((suffix[n - L] - suffix[n - R - 1] + MOD) % MOD
			* findMMI(power[n - R - 1]) % MOD)
			% MOD;

		// If both are equal then
		// the substring is a palindrome
		if (hash_LR == reverse_hash_LR) {
			if (isPalindrome(str, L, R) == true)
				printf("The Substring [%d %d] is a "
					"palindrome\n",
					L, R);
			else
				printf("The Substring [%d %d] is not a "
					"palindrome\n",
					L, R);
		}

		else
			printf("The Substring [%d %d] is not a "
				"palindrome\n",
				L, R);
	}

	return;
}

// A Dynamic Programming Based Approach to compute the
// powers of 101
void computePowers(unsigned long long int power[], int n)
{
	// 101^0 = 1
	power[0] = 1;

	for (int i = 1; i <= n; i++)
		power[i] = (power[i - 1] % MOD * p % MOD) % MOD;

	return;
}

/* Driver program to test above function */
int main()
{
	string str = "abaaabaaaba";
	int n = str.length();

	// A Table to store the powers of 101
	unsigned long long int power[n + 1];

	computePowers(power, n);

	// Arrays to hold prefix and suffix hash values
	unsigned long long int prefix[n + 1], suffix[n + 1];

	// Compute Prefix Hash and Suffix Hash Arrays
	computePrefixHash(str, n, prefix, power);
	computeSuffixHash(str, n, suffix, power);

	Query q[] = { { 0, 10 }, { 5, 8 }, { 2, 5 }, { 5, 9 } };
	int m = sizeof(q) / sizeof(q[0]);

	queryResults(str, q, m, n, prefix, suffix, power);
	return (0);
}
