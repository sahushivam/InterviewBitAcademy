/**
 *   author: sahushivam
 *	 https://www.spoj.com/problems/SALMAN/
 *   created: 09 November 2019 (Saturday)  15:10:08
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
vector<pair<int,int>>tree(2000005);
vector<int>lazy(2000005);
vector<pair<int,int>>a(500005);
vector<int>arr;
vector<int> pos;
int timer;
void init()
{
	arr.clear();
	pos.clear();

	for(int i=0;i<2000005;i++) lazy[i]=0;
	for(int i=0;i<2000005;i++) tree[i].first=0,tree[i].second=0;
	for(int i=0;i<500005;i++) a[i].first=0,a[i].second=0;
}

void build(int start,int end,int node)
{
	if(start==end)
	{
		tree[node].first=arr[start];
		tree[node].second=arr[start];
	}
	else
	{
		int mid = (start+end)/2;
		build(start,mid,2*node);
		build(mid+1,end,2*node+1);
		tree[node].first=tree[2*node].first+tree[2*node+1].first;
		tree[node].second=min(tree[2*node].second,tree[2*node+1].second);
	}
}

void update(int start,int end,int left,int right,int val,int node)
{	
	if(lazy[node])
	{
		tree[node].first+=(end-start+1)*lazy[node];
		tree[node].second+=lazy[node];
		if(start!=end)
		{	
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(left>end || right>end) return;
	if(left<=start && right>=end)
	{
		tree[node].first+=(end-start+1)*val;
		tree[node].second+=val;
		if(start!=end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return;
	}
	int mid=(start+end)/2;
	update(start,mid,left,right,val,2*node);
	update(mid+1,end,left,right,val,2*node+1);
	tree[node].second=min(tree[2*node].second,tree[2*node+1].second);
	tree[node].first=(tree[2*node].first+tree[2*node+1].first);
}

pair<int,int> query(int start,int end,int left,int right,int node)
{
	pair<int,int> res;
	if(start>end || left>end || right<start || left>right) 
	{
		res.first=0;
		res.second=INT_MAX;
		return res;
	}
	if(lazy[node])
	{
		tree[node].first+=(end-start+1)*lazy[node];
		tree[node].second+=lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(left<=start && right>=end) return tree[node];
	pair<int,int> l,r;
	int mid=(start+end)/2;
	l=query(start,mid,left,right,2*node);
	r=query(mid+1,end,left,right,2*node+1);
	l.first=(l.first+r.first);
	l.second=min(l.second,r.second);
	return l;
}

void dfs(vector<vector<int>>&graph,int parent,int node,vector<int>&size)
{
	pos[node]=timer++;
	arr.push_back(a[node].second);
	for(auto i: graph[node])
	{
		if(i!=parent)
		{
			dfs(graph,node,i,size);
			size[node]+=size[i];
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    int case1=1;
    while(t--)
    {
	    int n,q;
	    cin>>n>>q;
	    vector<vector<int>>graph(n);
	    init();
	    for(int i=0;i<n;i++)
	    {
	    	cin>>a[i].first>>a[i].second;
	    	if(a[i].first==0) continue;
	    	graph[a[i].first-1].push_back(i);
	    	graph[i].push_back(a[i].first-1);
	    }
	    vector<int> size(n,1);
	    pos.resize(n);
	    for(int i=0;i<n;i++) pos[i]=0;

	    timer=0;
	    dfs(graph,-1,0,size);
	    build(0,n-1,1);
	    cout<<"Case "<<case1++<<":\n";
	    while(q--)
	    {
	    	int a; cin>>a;
	    	if(a==1){
	    		int b;
	    		cin>>b;
	    		b--;
	    		int x=size[b];
	    		cout<<query(0,n-1,pos[b],pos[b]+x-1,1).first<<endl;
	    	}
	    	else
	    	{
	    		int b; cin>>b;
	    		b--;
	    		int x;
	    		x=size[b];
	    		int mini=query(0,n-1,pos[b],pos[b]+x-1,1).second;
	    		mini=min(mini,1000LL);
	    		//cout<<mini;
	    		update(0,n-1,pos[b],pos[b]+x-1,mini,1);
	    	}
	    }

	}
return 0;
}