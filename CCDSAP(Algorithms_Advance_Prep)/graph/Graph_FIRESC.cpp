/**
 *   author: sahushivam
 *   created: 07 July 2019 (Sunday)  17:47:13
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

//Approach- dfs on each connected components, find number of nodes in each connected component
// and ans is number of connected component , multiplication of each connected components
void dfs(ll v,std::vector<bool> &visited,vector<ll> G[],ll &c)
{
	visited[v]=true;
	c++;
	for(auto x: G[v])
	{
		if(!visited[x])
			dfs(x,visited,G,c);
	}
}
void solve()
{
	ll n,e;
	cin>>n>>e;
	std::vector<ll> v[n];
	ll a,b;
	for(ll i=0;i<e;i++)
	{
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<ll>ans;
	
	std::vector<bool> visited(n,false);
	for(ll i=0;i<n;i++)
	{
		ll c=0;
		if(!visited[i]){
			dfs(i,visited,v,c);
			ans.push_back(c);
		}
	}
	ll ans1=ans.size();
	ll ans2=1;
	for(ll i=0;i<ans.size();i++)
	{
		ans2=ans2*ans[i];
		ans2=ans2%1000000007;
	}
	cout<<ans1<<" "<<ans2<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
    	solve();
    }

return 0;
}