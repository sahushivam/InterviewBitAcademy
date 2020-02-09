/**
 *   author: sahushivam
 *   created: 22 January 2020 (Wednesday)  20:57:59
**/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long
#define N 1000000
bool isSquare(int n)
{
	int k=sqrt(n);
	if(k*k==n) return true; return false;
}
vector<bool> prime(N,true);
void Sieve()
{
	prime[0]=prime[1]=false;
	for(int i=2;i<N;i++)
	{
		if(prime[i]){
			for(int j=i*i;j<N;j+=i)
			{
				prime[j]=false;
			}
		}
	}
}
void solve(){
	int n; cin>>n;
	set<int> s;
	for(int i=2;i*i<n;i++)
	{
		if(n%i==0 && isSquare(n/i)==false)
		{
			int f=i;
			int s=n/i;
			for(int j=2;j*j<s;j++)
			{
 
				if(s%j==0 && i!=j && s/j!=i)
				{
					cout<<"Yes\n";
					cout<<f<<" "<<j<<" "<<s/j<<endl;
					return;
				}
			}
		}
	}
	cout<<"No\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}