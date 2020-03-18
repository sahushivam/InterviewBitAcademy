/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  10:58:17
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

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n,m,u,v;
    	cin>>n>>m>>u>>v;
    	u--; v--;
    	vector<pair<int,double>> graph[n+1];
    	for(int i=0;i<m;i++)
    	{
    		int a,b; double len,v;
    		cin>>a>>b>>len>>v;
    		double time=(double)len/(double)v;
    		a--; b--;
    		graph[a].PB({b,time});
    		graph[b].PB({a,time});
    	}

    	priority_queue< pair<double,int> , vector<pair<double,int>>, greater<pair<double,int>>> pq;
    	vector<double> time(n,999999999999.999);
    	vector<bool> visited(n,0);
    	pq.push({0, u});
    	time[u]=0;

    	while(!pq.empty())
    	{
    		pair<double,int> p=pq.top(); pq.pop();
    		double t=p.first;
    		int pa=p.second;
    		 if(visited[pa]) continue;

    		visited[pa]=1;

    		for(auto c: graph[pa])
    		{
    			double wei=c.second;
    			int node=c.first;
	    		if(time[node]>time[pa]+wei)
	    		{
	    			time[node]=time[pa]+wei;
	    			pq.push({time[node],node});
	   	 		}
    		}
    	}
    	if(time[v]==999999999999.999)
    	{
    		cout<<"-1\n";
    	}
    	else
    	{
    		cout<<fixed<<setprecision(10)<<time[v]<<endl;
    	}
    }
return 0;
}