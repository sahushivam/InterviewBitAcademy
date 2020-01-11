/**
 *   author: sahushivam
 *   created: 27 December 2019 (Friday)  20:06:37
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
	vector<int> a(3);
	for(int i=0;i<3;i++) cin>>a[i];
	sort(a.begin(),a.end());
	if(a[0]+a[1]+1>=a[2])
	{
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}	