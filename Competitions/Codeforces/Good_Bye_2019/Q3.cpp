/**
 *   author: sahushivam
 *   created: 29 December 2019 (Sunday)  19:20:33
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
	int s=0;
	int x=0;
	int num=0;
	for(int i=0;i<57;i++){
		num = num | 1LL<<i;}
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
		x=x^a[i];
	}
	int d=num^x;
	int z=2*num - (s+d);
	if(z%2==0)
	{
		cout<<3<<endl;
		cout<<d<<" "<<z/2<<" "<<z/2<<endl;
	}
	else
	{
		num--;
		d=num^x;
		z= 2*num - (s+d);
		cout<<3<<endl;
		cout<<d<<" "<<z/2<<" "<<z/2<<endl;
	}
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}