/**
 *   author: sahushivam
 *   created: 24 December 2019 (Tuesday)  20:09:00
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
	int a,b,c,r; cin>>a>>b>>c>>r;
	if(a>b) swap(a,b);
	int d=c-r, e=c+r;
	if(e<a || d>b) 
	{
		cout<<b-a<<"\n"; return;
	}
	else
	{
		int ans=min(b-a,min(e,b)-max(d,a));
		cout<<(b-a) - ans<<endl;
		return;
	}
}
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}