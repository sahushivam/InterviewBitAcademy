/**
 *   author: sahushivam
 *   created: 18 August 2019 (Sunday)  18:13:47
 *   find size of all subtree  
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int timer=0;
int dfs(int parent,int v,vector<int> &size,vector<vector<int>> &adj,vector<int> &pos)
{
    timer++;
    pos[v]=timer;
    for (int u : adj[v]) {
        if (u!=parent)
            size[v]+=dfs(v,u,size,adj,pos);
    }
    return size[v];
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,q,a,b;
    cin>>n>>q;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++) 
    {
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> size(n,1),pos(n,0);
    dfs(-1,0,size,adj,pos);
    vector<int> prefix(n+1,0);
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        prefix[pos[a-1]]+=b;
        prefix[pos[a-1]+size[a-1]]-=b;
    }
    for(int i=1;i<n+1;i++)
        prefix[i]+=prefix[i-1];
    for(int i=0;i<n;i++)
        cout<<prefix[pos[i]]<<" ";
return 0;
}
