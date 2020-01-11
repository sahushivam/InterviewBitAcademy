/**
 *   author: sahushivam
 *   created: 29 December 2019 (Sunday)  19:20:38
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

void solve(){
	int n,k1,k2;
	cin>>n>>k1>>k2;
	int maxi1=-1,maxi2=-1;
	int a;
	for(int i=0;i<k1;i++)
	{
		cin>>a; maxi1=max(maxi1,a);
	}
	for(int i=0;i<k2;i++)
	{
		cin>>a; maxi2=max(maxi2,a);
	}
	if(maxi1>maxi2)
	{
		cout<<"YES\n";
	}
	else cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}