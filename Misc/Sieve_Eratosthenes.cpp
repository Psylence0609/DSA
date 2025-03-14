
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve_till_root(int n) // Time= nlnln(n^(1/2))
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

/**
Segmented Sieve
It follows from the optimization "sieving till root" that there is no need to keep the whole array is_prime[1...n] at all time.
For sieving it is enough to just keep the prime numbers until the root of n, i.e. prime[1... sqrt(n)], split the complete range into blocks, and sieve each block separately.

Let s be a constant which determines the size of the block, then we have ⌈ns⌉ blocks altogether, and the block k (k=0...⌊ns⌋) contains the numbers in a segment [ks;ks+s−1].
We can work on blocks by turns, i.e. for every block k we will go through all the prime numbers (from 1 to n−−√) and perform sieving using them.
It is worth noting, that we have to modify the strategy a little bit when handling the first numbers: first, all the prime numbers from [1;n−−√] shouldn't remove themselves; and second, the numbers 0 and 1 should be marked as non-prime numbers.
While working on the last block it should not be forgotten that the last needed number n is not necessary located in the end of the block.

As discussed previously, the typical implementation of the Sieve of Eratosthenes is limited by the speed how fast you can load data into the CPU caches.
By splitting the range of potential prime numbers [1;n] into smaller blocks, we never have to keep multiple blocks in memory at the same time, and all operations are much more cache-friendlier.
As we are now no longer limited by the cache speeds, we can replace the vector<bool> with a vector<char>, and gain some additional performance as the processors can handle read and writes with bytes directly and don't need to rely on bit operations for extracting individual bits.
The benchmark (link) shows, that using a vector<char> is about 3x faster in this situation than using a vector<bool>. A word of caution: those numbers might differ depending on architecture, compiler, and optimization levels.

Here we have an implementation that counts the number of primes smaller than or equal to n using block sieving.
**/

int count_primes(int n)
{
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++)
    {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes)
        {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++)
        {
            if (block[i])
                result++;
        }
    }
    return result;
}

/**
Find primes in range
Sometimes we need to find all prime numbers in a range [L,R] of small size (e.g. R−L+1≈1e7), where R can be very large (e.g. 1e12).

To solve such a problem, we can use the idea of the Segmented sieve. We pre-generate all prime numbers up to sqrt(R), and use those primes to mark all composite numbers in the segment [L,R].
**/
vector<char> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

/**
Time complexity of this approach is O((R−L+1)loglog(R)+R−−√loglogR−−√).

It's also possible that we don't pre-generate all prime numbers:
**/

vector<char> segmentedSieveNoPreGen(long long L, long long R)
{
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

// main
int main()
{
    int n;
    cin >> n;
    vector<bool> sieve = sieve_till_root(n);
    int number = count_primes(n);
    for (auto it = sieve.begin(); it < sieve.end(); it++)
        cout << *it << endl;
    cout << number;
}