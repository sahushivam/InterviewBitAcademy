/**
 *   author: sahushivam
 *   created: 28 December 2019 (Saturday)  19:56:39
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

vector<int> factors(int n)
{
	std::vector<int> v;
	for(int i=1;i*i<n;i++)
	{	
		if(n%i==0){
			v.push_back(i);
			v.push_back(n/i);
		}
	}
	int s=sqrt(n);
	if(s*s==n) v.push_back(s);
	return v;
}

void solve(){
	int a,m; cin>>a>>m;
	vector<int> fac = factors(m), ans;
	for(int i : fac)
	{
		int l= m/i;
		l--;
		if(l%a==0)
		{
			ans.push_back(i* (l/a));
		}
	}

	sort(ans.begin(),ans.end());
	cout<<ans.size()-1<<'\n';
	for(int i: ans){
		if(i!=0)
		cout<<i<<" ";
	}
	cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}