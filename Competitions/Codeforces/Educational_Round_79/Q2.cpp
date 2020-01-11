/**
 *   author: sahushivam
 *   created: 27 December 2019 (Friday)  20:17:45
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n,s; cin>>n>>s;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> pre(n);
	pre[0]=a[0];
	for(int i=1;i<n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	if(pre[n-1]<=s)
	{
		cout<<"0\n";
		return;
	}

	int ans=-1,ans2=1;
	for(int i=0;i<n;i++)
	{
		if(pre[i]>s+a[i]) break;
		int j=lower_bound(pre.begin(),pre.end(),a[i]+s+1)-pre.begin();
		if(ans<j)
		{
			ans=j;
			ans2=i+1;
		}
	}
	cout<<ans2<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}