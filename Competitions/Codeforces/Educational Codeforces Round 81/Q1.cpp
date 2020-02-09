/**
 *   author: sahushivam
 *   created: 29 January 2020 (Wednesday)  20:04:47
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
	int n;
	cin>>n;
	string ans="";
	if(n&1)
	{
		n=n-3;
		if(n>=0) ans+="7";
		n=n/2;
		for(int i=0;i<n;i++)
			ans=ans+"1";
		
	}
	else
	{
		n=n/2;
		for(int i=0;i<n;i++)
			ans+="1";
	}
	cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}