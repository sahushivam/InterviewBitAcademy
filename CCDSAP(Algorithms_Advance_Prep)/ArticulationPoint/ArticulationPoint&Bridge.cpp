/**
 *   author: sahushivam
 *   created: 03 September 2019 (Tuesday)  15:24:33
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000009
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair


//If a vertex u is having a child v such that the earliest discovered vertex that can be reached from the vertices in the subtree rooted at v has a discovery time greater than or equal to u, then  does not have a back edge, and thus  will be an articulation point.


//It is an array of N elements which stores, for every vertex v, the discovery time of the earliest discovered vertex to which v or any of the vertices in the subtree rooted at v is having a back edge. It is initialized by INFINITY.

int timer,c,root,bridge;
set<int> ans;
vector<pair<int,int> >bridg;
vector<int> visited;
vector<int> low;
void dfs(int u, int p,vector<vector<int> > &adj){
	visited[u] = low[u] = ++timer;
	for(auto v: adj[u]){
		if(v == p) continue;
		if(visited[v]){
			low[u] = min(low[u], visited[v]);
		}
		else{
			dfs(v,u,adj);
			low[u] = min(low[u], low[v]);
			if(visited[u] <= low[v] && u != -1){
				ans.insert(u);
			}
            c++;
			if(visited[u] <low[v]){
				bridg.push_back({u,v});
				bridge++;
			}
			
		}
	}
    if(p==-1 && c>1)
        ans.insert(v);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    visited.resize(n);
    low.resize(n);
       int a,b;
    timer=0,c=0,root=0,bridge=0;
    for(int i=0;i<m;i++)
    {
    	cin>>a>>b;
    	adj[a].PB(b);
    	adj[b].PB(a);
    }
    dfs(0,-1,adj);
    int articulationPoint=ans.size();
    if(c>=1)
    	articulationPoint++;
    cout<<articulationPoint<<endl;
    for(auto a: ans)
    	cout<<a<<endl;
    cout<<bridge<<endl;
    sort(bridg.begin(),bridg.end());
    for(auto a: bridg)
    {
    	cout<<a.first<<" "<<a.second<<endl;
    }


return 0;
}