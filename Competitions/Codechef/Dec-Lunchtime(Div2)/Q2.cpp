/**
 *   author: sahushivam
 *   created: 28 December 2019 (Saturday)  19:47:01
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
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=0; int mini=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(a[i]<mini)
		{
			ans+=a[i];
		}
		else
		{
			ans+=mini;
		}
		mini=min(mini,a[i]);
	}
	cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}