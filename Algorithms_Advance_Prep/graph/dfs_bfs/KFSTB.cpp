/**
 *   author: sahushivam
 *   created: 08 November 2019 (Friday)  19:34:02
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

void dfs(vector<vector<int>> &graph,vector<int> &visited, vector<int> &path,int node)
{
	visited[node]=1;
	for(auto i: graph[node])
	{
		if(!visited[i])
			dfs(graph,visited,path,i);
	}
	path.PB(node);
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n,m,s,t,e1,e2;
    	cin>>n>>m>>s>>t; s--; t--;
    	vector<vector<int>> graph(n);
    	std::vector<int> dp(n, 0);
    	for(int i=0;i<m;i++)
    	{
    		cin>>e1>>e2;
    		e1--; e2--;
    		graph[e1].PB(e2);
    	}
    	vector<int> visited(n,0);
    	vector<int> path;
    	dfs(graph,visited,path,s);
    	reverse(path.begin(),path.end());
    	dp[path[0]]=1;
    	for(auto i: path)
    	{
    		for(auto j: graph[i]){
    			dp[j] += dp[i];
    			dp[j] %= MOD;
    		}
    	}
    	cout<<dp[t]<<endl;
    }
return 0;
}