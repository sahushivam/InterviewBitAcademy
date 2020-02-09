/**
 *   author: sahushivam
 *   created: 22 January 2020 (Wednesday)  20:16:22
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
 
bool comp(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first==p2.first) return p1.second<p2.second;
	return p1.first<p2.first;
}
void solve(){
	int n; cin>>n;
	vector<pair<int,int>> point(n);
	for(int i=0;i<n;i++)
		cin>>point[i].first>>point[i].second;
	sort(point.begin(),point.end(),comp);
 
	int intx=0,inty=0;
	string ans="";
	for(int i=0;i<n;i++)
	{
		int desx=point[i].first;
		int desy=point[i].second;
		if(desy<inty)
		{
			cout<<"NO\n";
			return;
		}
		else if(desx<intx)
		{
			cout<<"NO\n";
			return;
		}
		else
		{
			while(desx != intx){
				ans+='R';
				intx++;
			}
			while(desy != inty){
				ans+='U';
				inty++;
			}
		}
 
	}
	cout<<"YES"<<endl;
	cout<<ans<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}
