/**
 *   author: sahushivam
 *   created: 12 January 2020 (Sunday)  17:49:32
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

int k=0;

void solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> graph(n*m);
	vector<string> ss;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		ss.PB(s);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ss[i][j]=='.'){
				if(i+1 < n and ss[i+1][j]=='.')
				{
					graph[i*m+j].PB({1,(i+1)*m+j});
				}
				if(j+1 <m and ss[i][j+1]=='.')
				{
					graph[i*m+j].PB({1,i*m+(j+1)});
				}
				if(i-1>=0 and ss[i-1][j]=='.')
				{
					graph[i*m+j].PB({1,(i-1)*m+j});
				}
				if(j-1>= 0 and ss[i][j-1]=='.')
				{
					graph[i*m+j].PB({1,i*m+(j-1)});
				}
			}
		}
	}

	int ans=0;

	for(int i=0;i<n*m;i++)
	{
		k=0;
		if(ss[i/m][i%m]!='.') continue;
		vector<int>dist(n*m,INT_MAX);
		priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
	    int source=i;
	    q.push({0,source}); dist[source]=0;
	    while(!q.empty())
	    {
	    	int v=q.top().second;
	    	q.pop();
	    	for(auto u:graph[v])
	    	{
	    		int wei=u.first;
	    		int node=u.second;
	    		if(dist[node]>dist[v]+wei)
	    		{
	    			dist[node]=dist[v]+wei;
	    			q.push({dist[node],node});
	    		}
	    	}
	    }
		for(int i=0;i<n*m;i++)
		{
			if(dist[i]!=INT_MAX)
				ans=max(ans,dist[i]);
		}
	}
	cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}