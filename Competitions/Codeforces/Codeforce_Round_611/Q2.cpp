/**
 *   author: sahushivam
 *   created: 28 December 2019 (Saturday)  22:38:46
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
	int c, k;
	cin>>c>>k;
	int h=c/k;
	int div=c%k;
	if(div>k/2)
	{
		cout<<h*k + k/2;
	}
	else
	{
		cout<<c;
	}
	cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}