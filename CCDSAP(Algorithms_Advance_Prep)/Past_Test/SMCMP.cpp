/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  11:26:35
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

vector<int> parent(100005);
int find(int u)
{
	if(parent[u]==u)
		return u;
	else
	{
		return parent[u]=find(parent[u]);
	}
}
void union1(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
		parent[a]=b;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) parent[i]=i;
    while(q--)
    {
    	int nn;
    	cin>>nn;
    	if(nn==1)
    	{
    		int a,b; cin>>a>>b;
    		union1(a,b);
    	}
    	else
    	{
    		int a, b; cin>>a>>b;
    		if(find(a)==find(b))
    		{
    			cout<<"Yes\n";
    		}
    		else
    		{
    			cout<<"No\n";
    		}
    	}
    }
return 0;
}