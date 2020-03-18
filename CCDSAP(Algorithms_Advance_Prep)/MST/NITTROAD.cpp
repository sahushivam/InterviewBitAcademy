/**
 *   author: sahushivam
 *   created: 10 November 2019 (Sunday)  15:35:19
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

vector<int> parent;
vector<int> size;
int total_pair;
int find(int v)
{
	if(parent[v]==v)
		return v;
	return 	parent[v]=find(parent[v]);
}

void union1(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		if(size[a]>size[b]){
			total_pair+=(size[a]*(size[a]-1)/2);
			total_pair+=(size[b]*(size[b]-1)/2);
			total_pair-=(((size[b]+size[a])*(size[a]+size[b]-1))/2);
			size[a]+=size[b];
			parent[b]=a;
			size[b]=0;
		}
		else
		{
			total_pair+=(size[a]*(size[a]-1)/2);
			total_pair+=(size[b]*(size[b]-1)/2);
			total_pair-=(((size[b]+size[a])*(size[a]+size[b]-1))/2);
			size[b]+=size[a];
			parent[a]=b;
			size[a]=0;
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n;	cin>>n;
    	vector<pair<int,int>> edges(n-1);
    	for(int i=0;i<n-1;i++)
    	{
    		int a,b; cin>>a>>b;
    		edges[i]={--a,--b};
    	}
    	int q;
    	cin>>q;
    	vector<pair<int,int>> query(q);
    	vector<int> alwaysCon(n-1,1);
    	for(int i=0;i<q;i++)
    	{
    		char c; int a=-1;
    		cin>>c;
    		if(c=='R')
    		{	
    			cin>>a;
    			a--;
    			alwaysCon[a]=0;
    		}
    		query[i]={c,a};
    	}

    	parent.resize(n); size.resize(n);
    	for(int i=0;i<n;i++) size[i]=1;

    	for(int i=0;i<n;i++) parent[i]=i;
    	int initial=0;
    	total_pair=(n*(n-1))/2;
    	for(int i=0;i<n-1;i++)
    	{
    		if(alwaysCon[i])
    		{
    			pair<int,int> p= edges[i];
    			union1(p.first,p.second);
    		}
    	}
    	int total=(n*(n-1))/2;
    	vector<int> ans;
    	for(int i=q-1;i>=0;i--)
    	{
    		pair<int,int> p=query[i];
    		int node=p.second;
    		
    			if(p.first=='R'){
					pair<int,int> ss=edges[node];
					union1(ss.first,ss.second);
				}
				else{
					//cout<<total_pair<<endl;
    				ans.push_back(total_pair);
    			}
    	}
    	reverse(ans.begin(),ans.end());
    	for(auto i: ans) cout<<i<<endl;
    	cout<<endl;
    }
return 0;
}