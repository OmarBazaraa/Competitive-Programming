#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

// =====================================================================================

/**
 * Computes the greatest common divisors (GCD) of the given two numbers.
 * Worst case time complexity when (a, b) are two consecutive Fibonacci numbers.
 *
 * Complexity: O(log(max(a, b))
 *
 * @return the GCD of "a" and "b".
 */
template<class T>
T gcd(T a, T b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// =====================================================================================

/**
 * Computes the least common multiple (LCM) of the given two numbers.
 * Worst case time complexity when (a, b) are two consecutive Fibonacci numbers.
 *
 * Complexity: O(log(max(a, b))
 *
 * @return the LCM of "a" and "b".
 */
template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

// =====================================================================================

/**
 * Computes the Bezout's coefficients of the smallest positive linear combination of "a" and "b".
 * using the extended Euclidean algorithm.
 * (i.e. GCD(a, b) = s.a + t.b).
 *
 * Complexity: O(log(max(a, b))
 *
 * @return the Bezout's coefficients: "s" and "t".
 */
template<class T>
pair<T, T> extendedEuclid(T a, T b) {
    if (b == 0) {
        return {1, 0};
    }

    pair<T, T> p = extendedEuclid(b, a % b);

    T s = p.first;
    T t = p.second;

    return {t, s - t * (a / b)};
}

// =====================================================================================

/**
 * Raises a number to the given power using iterative fast power algorithm.
 * Note that if (base=0, exp=0) is passed to the function it will return 1.
 *
 * Complexity: O(log(exp))
 *
 * @param base the base number.
 * @param exp  the exponent.
 * @param mod  the modulus.
 *
 * @return ((base^exp) % mod).
 */
template<class T>
T power(T base, T exp, T mod) {
    T ans = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }

    return ans;
}

// =====================================================================================

/**
 * Computes the modular inverse of "a" modulo "m".
 * (i.e. (a * mod_inverse(a)) == 1 (mod m)).
 *
 * Note that the function works correctly only if "m" is a prime number.
 *
 * Complexity: O(log(m))
 *
 * @param a the number to compute its modular inverse.
 * @param m the modulus. Must be a prime number.
 *
 * @return the modular inverse of "a" modulo "m".
 */
template<class T>
T modInverse(T a, T m) {
    return power(a, m - 2, m);
}

// =====================================================================================

/**
 * Computes the number of distinct sets of size "r" chosen from "n" items.
 *
 * Note that C(n, r) = C(n, n - r).
 * So call the function with nCr(n, min(r, n-r)) for better performance.
 *
 * Complexity: O(r)
 *
 * @return "n" choose "r".
 */
int nCr(int n, int r) {
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}

// =====================================================================================

// fact[i] : holds the value of the factorial of integer "i" (i.e. "i!" modulo "mod").
int fact[N];

/**
 * Pre-computes the factorial array (from "fact[0]" to "fact[n]")
 * modulo a given number.
 * 
 * Call this function once before using the "nCr" function below.
 *
 * @param n   the number of factorials to populate.
 * @param mod the modulus.
 */
void init(int n, int mod) {
    fact[0] = 1;

    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * 1LL * i) % mod;
    }
}

/**
 * Computes the number of distinct sets of size "r" chosen from "n" items
 * modulo a given number.
 *
 * This function can only be used after populating the factorial array
 * using the above function "init" with the same modulus.
 *
 * Complexity: O(log(mod))
 *
 * @return "n" choose "r".
 */
int nCr(int n, int r, int mod) {
    return (fact[n] * modInverse(fact[r] * 1LL * fact[n - r], mod + 0LL)) % mod;
}

// =====================================================================================

// comb[n][r] : holds the value of "n" choose "r" modulo "mod".
int comb[N][N];

/**
 * Builds Pascal's triangle for computing combinations (i.e. "nCr").
 * After calling this function, "comb[n][r]" will be equals to "nCr".
 *
 * Complexity: O(n^2)
 *
 * @param n   the size of Pascal's triangle to build.
 * @param mod the modulus.
 */
void buildPT(int n, int mod) {
    for (int i = comb[0][0] = 1; i <= n; ++i)
        for (int j = comb[i][0] = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
}

// =====================================================================================

/**
 * Checks whether an integer is prime or not.
 *
 * Complexity: O(sqrt(n))
 *
 * @param n a positive integer to check its integer primality.
 *
 * @return {@code true} if "n" is prime; {@code false} otherwise.
 */
template<class T>
bool isPrime(T n) {
    if (n < 2)
        return 0;
    if (n % 2 == 0)
        return (n == 2);
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

// =====================================================================================

/**
 * Probabilistic test of Miller Rabin algorithm for an integer "n".
 * Note that: "n - 1 = power(2, k) * q".
 *
 * This function is to be called internally from "isPrimeMillerRabin" function.
 * Do not call it directly.
 *
 * @return {@code false} if "n" is a composite number; {@code true} if it is a probable prime.
 */
template<class T>
bool millerRabinTest(T a, T k, T q, T n) {
    T x = power<long long>(a, q, n);

    if (x == 1) {
        return true;
    }

    while (k--) {
        if (x == n - 1) {
            return true;
        }

        x = (x * 1LL * x) % n;
    }

    return false;
}

/**
 * Checks whether an integer is prime or not using a deterministic method of
 * Miller Rabin algorithm.
 *
 * Complexity: O(t.log(n))
 *
 * @param n a positive integer to check its integer primality.
 *
 * @return {@code true} if "n" is prime; {@code false} otherwise.
 */
template<class T>
bool isPrimeMillerRabin(T n) {
    if (n == 2) {
        return true;
    }

    if (n < 2 || n % 2 == 0) {
        return false;
    }

    // Compute coefficients k, q such that "n - 1 = power(2, k) * q"
    T k = 0;
    T q = n - 1;
    while ((q & 1) == 0) {
        k++;
        q >>= 1;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (n == a) {
            return true;
        }

        if (!millerRabinTest(a, k, q, n)) {
            return false;
        }
    }

    return true;
}

// =====================================================================================

// prime[i] : true if integer "i" is prime; false otherwise.
bool prime[N];

/**
 * Generates all the prime numbers of the integers from 1 to "n"
 * using Sieve of Eratosthenes' algorithm.
 * After calling this function, "prime[i]" will be equal true if "i" is prime; false otherwise.
 *
 * Complexity: O(n.log(log(n)))
 */
void generatePrimes(int n) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (!prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
}

// =====================================================================================

// divs[i] : holds a list of all the prime divisors of integer "i".
vector<int> primeDivs[N];

/**
 * Generates all the prime divisors of the integers from 1 to "n".
 * After calling this function, "primeDivs[i]" will contains all the prime divisors of integer "i".
 *
 * Complexity: O(n.log(log(n)))
 */
void generatePrimeDivisors(int n) {
    for (int i = 2; i <= n; ++i) {
        if (primeDivs[i].size()) continue;

        for (int j = i; j <= n; j += i) {
            primeDivs[j].push_back(i);
        }
    }
}

// =====================================================================================

/**
 * Computes all the divisors of a positive integer.
 *
 * Complexity: O(sqrt(n))
 *
 * @param n the positive integer to compute its divisors.
 *
 * @return a sorted list of all the divisors of "n".
 */
template<class T>
vector<T> getDivisors(T n) {
    vector<T> divs;
    for (T i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        divs.push_back(i);
        if (i * i == n) continue;
        divs.push_back(n / i);
    }
    sort(divs.begin(), divs.end());
    return divs;
}

// =====================================================================================

// divs[i] : holds a list of all the divisors of integer "i".
vector<int> divs[N];

/**
 * Generates all the divisors of the integers from 1 to "n".
 * After calling this function, "divs[i]" will contains all the divisors of integer "i".
 *
 * Complexity: O(n.log(n))
 */
void generateDivisors(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j].push_back(i);
}

// =====================================================================================