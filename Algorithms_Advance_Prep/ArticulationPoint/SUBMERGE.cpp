/**
 *   author: sahushivam
 *   created: 11 November 2019 (Monday)  11:13:22
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long

vector<int> gp[100005];
vector<int> tin(100005),low(100005),visited(100005);
int timer;
set<int> ans;
void dfs(int v,int p)
{
	visited[v]=1;
	tin[v]=low[v]=timer++; 
	int child=0;
	for(auto i: gp[v])
	{
		if(i==p) continue;
		if(visited[i])
		{
			low[v]=min(low[v],tin[i]);
		}
		else
		{
			dfs(i,v);
			low[v]=min(low[v],low[i]);
			if(tin[v] <= low[i] && p != -1){ // child low time is greater than parent
				ans.insert(v);
			}
			child++;
		}
	}
	if(p==-1 && child>1)
		ans.insert(v);
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    while(1)
    {
    	int n,m; cin>>n>>m;
    	if(n==0) break;
    	for(int i=0;i<100005;i++) tin[i]=0, visited[i]=0;
    	for(int i=0;i<100005;i++) gp[i].clear();
    	ans.clear();
    	timer=0;
    	for(int i=0;i<m;i++)
    	{
    		int a,b; cin>>a>>b;
    		a--; b--;
    		gp[a].PB(b);
    		gp[b].PB(a);
    	}
    	for(int i=0;i<n;i++)
    		if(!visited[i])
    			dfs(i,-1);
    	cout<<ans.size()<<endl;
    }
return 0;
}