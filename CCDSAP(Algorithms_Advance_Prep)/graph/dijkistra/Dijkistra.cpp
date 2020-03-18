/**
 *   author: sahushivam
 *   created: 11 July 2019 (Thursday)  14:49:24
**/

/** Very Important**/

// If only considering about edge weight, then for the key part of dijkstra's algorithm, we have:

// if (distance[y] > distance[v]+weight) {
//     distance[y] = distance[v]+weight; // weight is between v and y
// }

// Now, by considering about vertex weight, we have:

// if (distance[y] > distance[v] + weight + vertexWeight[y]) {
//    distance[y] = distance[v] + weight + vertexWeight[y]; // weight is between v and y
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m,a,b,weight;
    cin>>n>>m;
    vector<pair<int,int> > G[n];
    vector<int>dist(n,INT_MAX);
    for(int i=0;i<m;i++)
    {
    	cin>>a>>b>>weight;
    	G[a].push_back({weight,b});
    	G[b].push_back({weight,a});
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > p;
    int source;
    cin>>source;
    p.push({0,source}); dist[source]=0;

    while(!p.empty())
    {
    	int v=p.top().second;
    	p.pop();
    	for(auto u:G[v])
    	{
    		int wei=u.first;
    		int node=u.second;
    		if(dist[node]>dist[v]+wei)
    		{
    			dist[node]=dist[v]+wei;
    			p.push({dist[node],node});
                //parent[node]=v;
    		}
    	}
    }
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);
return 0;
}