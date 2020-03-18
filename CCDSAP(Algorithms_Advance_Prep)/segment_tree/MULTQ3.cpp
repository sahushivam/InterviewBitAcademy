/**
 *   author: sahushivam
 *   created: 15 November 2019 (Friday)  10:20:05
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
#define N 500005
vector<int> a(N),tree(N),lazy(N);

void update(int s,int e,int l,int r,int n,int v)
{
	if(lazy[n])
	{
		tree[n]+=lazy[n];
		if(start!=end)
		{
			lazy[2*n]+=lazy[n];
			lazy[2*n+1]+=lazy[n];
		}
		lazy[n]=0;
	}
	if(s>e || l>r || r<s || l>e) return;
	else
	{
		int mid=(s+e)/2;
		update(s,mid,l,)
	}
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>n>>q;
    while(q--)
    {
    	int a,b,c; cin>>a>>b>>c; b--,c--;
    	if(a==1)
    	{
    		update(0,n,b,c,1,1);
    	}
    	else
    	{
    		cout<<query(0,n,b,c,1);
    	}
    }
return 0;
}