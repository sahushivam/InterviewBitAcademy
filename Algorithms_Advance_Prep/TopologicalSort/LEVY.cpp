/**
 *   author: sahushivam
 *   created: 13 November 2019 (Wednesday)  16:02:05
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long


#define MAX 10000
#define SQRT_MAX 100
int composite[1 + MAX];
int primes[1 + MAX];
int primeCount;

void sieve()
{
	int i, j;
	int sq = SQRT_MAX;
	composite[0] = composite[1] = 1;
	for (i = 2; i <= sq; ++i)
		if (!composite[i])
		{
			primes[primeCount++] = i;
			for (j = i * i; j <= MAX; j += i)
				composite[j] = 1;
		}
	for (; i <= MAX; ++i)
		if (!composite[i])
			primes[primeCount++] = i;
}

signed main()
{
	int t;
	scanf("%d", &t);
	sieve();
	while (t--)
	{
		int n, p, q, count;
		scanf("%d", &n);
		count = 0;
		for (q = 0; q < primeCount && primes[q] < n; ++q)
		{
			p = n - 2*primes[q];
			if (p > 1 && !composite[p])
				++count;
		}
		printf("%d\n", count);
	}
	return 0;
}