/**
 *   author: sahushivam
 *   created: 12 January 2020 (Sunday)  16:50:15
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
	int n,m; cin>>n>>m;
	vector<int> a(n,0),cor(n,0);
	int p; string s;
	int wrong=0;
	for(int i=0;i<m;i++)
	{
		cin>>p>>s;
		if(s=="AC"){
			cor[p-1]=1;
		}
		if(cor[p-1]==0 && s=="WA") a[p-1]++; 
	}
	int correct=0;
	for(int i=0;i<n;i++)
	{
		if(cor[i]) {correct++; wrong+=a[i];}
	}
	cout<<correct<<" "<<wrong<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}