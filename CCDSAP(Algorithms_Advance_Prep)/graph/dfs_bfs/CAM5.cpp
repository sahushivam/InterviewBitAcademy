/**
 *   author: sahushivam
 *   created: 08 November 2019 (Friday)  18:45:43
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

void dfs(vector<vector<int>> &graph,vector<int> &visited,int node,int parent)
{
	visited[node]=1;
	for(auto c: graph[node])
	{
		if(c!=parent && !visited[c])
		{
			dfs(graph,visited,c,node);
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > graph(n);
	    for(int i=0;i<m;i++)
	    {
	    	int a,b;
	    	cin>>a>>b;
	    	graph[a].PB(b);
	    	graph[b].PB(a);
	    }
	    vector<int> visited(n,0);
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	    	if(!visited[i])
	    	{
	    		dfs(graph,visited,i,-1);
	    		ans++;
	    	}
	    }
	    cout<<ans<<'\n';
	}
return 0;
}