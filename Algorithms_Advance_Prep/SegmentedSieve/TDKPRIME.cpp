/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  18:47:34
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
#define MAX 100000000
vector<bool> prime(MAX,true);
vector<int> primes;
void seive()
{
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++)
	{
		if(prime[i]){
			for(int j=i*i;j<MAX;j+=i)
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
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    seive();
    while(t--)
    {
    	int n;
    	cin>>n;
    	if(n>=1 && n<MAX)
    		cout<<primes[n-1]<<'\n';
    }
return 0;
} 