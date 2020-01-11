/**
 *   author: sahushivam
 *   created: 29 December 2019 (Sunday)  19:20:35
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

	for(int i=1;i<n;i++)
	{
		if(abs(a[i]-a[i-1])>=2)
		{
			cout<<"YES\n";
			cout<<i<<" "<<i+1<<endl;
			return;
		}
	}
	cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}