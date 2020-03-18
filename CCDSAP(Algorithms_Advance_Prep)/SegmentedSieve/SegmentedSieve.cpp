/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  16:58:39
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
#define MAX 1000006
vector<bool> prime(MAX,true);
vector<int> primes;
void seive()
{
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++)
	{
		if(prime[i]){
			for(int j=i*i;j<1000006;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	for(int i=2;i<MAX;i++)
	{
		if(prime[i])
			primes.PB(i);
	}
}

vector<int> segmented_seive(int l,int r)
{
	vector<int> isPrime(r-l+1,true);
	for(int i=0;primes[i]*primes[i]<=r;i++)
	{
		int curr_prime=primes[i];
		int base=(l/curr_prime)*curr_prime;
		if(base<l) base+=curr_prime;

		for(int j=base;j<=r;j+=curr_prime)
		{
			isPrime[j-l]=false;
		}
		
		if(base==curr_prime)
			isPrime[base-l]=true;
	}
	return isPrime;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;

return 0;
}