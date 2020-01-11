/**
 *   author: sahushivam
 *   created: 10 January 2020 (Friday)  19:49:49
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
	int n; cin>>n;
	int ans=INF; 
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0 && __gcd(i,n/i)==1)
		{
			ans=min(ans,max(i,n/i));
		}
	}
	if(ans<n/ans)
	cout<<ans<<" "<<n/ans;
	else
	cout<<n/ans<<" "<<ans;
}
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}