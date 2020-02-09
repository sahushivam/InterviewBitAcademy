/**
 *   author: sahushivam
 *   created: 11 January 2020 (Saturday)  16:29:46
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
	vector<pair<string,int>> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].F>>a[i].S;
	} 
	string ss;
	cin>>ss;
	int h=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].F==ss)
		{
			h=i;
			break;
		}
	}
	for(int i=h+1;i<n;i++)
	{
		sum+=a[i].S;
	}
	cout<<sum;

}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}